#include "din_fuzzy.h"

extern adcsample_t adc0;
extern float ax,ay,az;

static float f_accel[3];
static float f_mic[3];
static float f_rule[RULE_SIZE];

static double vf_accel_rendah[2] = {17.79, 27.44};
static double vf_accel_sedang[3] = {18.49, 26.94, 31.83};
static double vf_accel_tinggi[2] = {27.44, 31.33};

static unsigned int vf_mic_rendah[2] = {473, 542};
static unsigned int vf_mic_sedang[3] = {473, 542, 591};
static unsigned int vf_mic_tinggi[2] = {542, 591};

static void Accel(float input_accel){
    // fuzzy RENDAH
    if(input_accel <= vf_accel_rendah[0]){
        f_accel[0] = 1;
    }
    else if((input_accel > vf_accel_rendah[0]) && (input_accel <= vf_accel_rendah[1])){
        f_accel[0] = (vf_accel_rendah[1] - input_accel)/(vf_accel_rendah[1] - vf_accel_rendah[0]);
    }
    else if(input_accel > vf_accel_rendah[1]){
        f_accel[0] = 0;
    }

    // fuzzy SEDANG
    if(input_accel <= vf_accel_sedang[0]){
        f_accel[1] = 0;
    }
    else if((input_accel > vf_accel_sedang[0]) && (input_accel <= vf_accel_sedang[1])){
        f_accel[1] = (input_accel - vf_accel_sedang[0])/(vf_accel_sedang[1] - vf_accel_sedang[0]);
    }
    else if((input_accel > vf_accel_sedang[1]) && (input_accel <= vf_accel_sedang[2])){
        f_accel[1] = (vf_accel_sedang[2] - input_accel)/(vf_accel_sedang[2] - vf_accel_sedang[1]);
    }
    else if(input_accel > vf_accel_sedang[2]){
        f_accel[1] = 0;
    }

    // fuzzy TINGGI
    if(input_accel <= vf_accel_tinggi[0]){
        f_accel[2] = 0;
    }
    else if((input_accel > vf_accel_tinggi[0]) && (input_accel <= vf_accel_tinggi[1])){
        f_accel[2] = (input_accel - vf_accel_tinggi[0])/(vf_accel_tinggi[1] - vf_accel_tinggi[0]);
    }
    else if(input_accel > vf_accel_tinggi[1]){
        f_accel[2] = 1;
    }
}

static void Mic(unsigned int input_mic){
    // fuzzy RENDAH
    if(input_mic <= vf_mic_rendah[0]){
        f_mic[0] = 1;
    }
    else if((input_mic > vf_mic_rendah[0]) && (input_mic <= vf_mic_rendah[1])){
        f_mic[0] = (vf_mic_rendah[1] - input_mic)/(vf_mic_rendah[1] - vf_mic_rendah[0]);
    }
    else if(input_mic > vf_mic_rendah[1]){
        f_mic[0] = 0;
    }

    // fuzzy SEDANG
    if(input_mic <= vf_mic_sedang[0]){
        f_mic[1] = 0;
    }
    else if((input_mic > vf_mic_sedang[0]) && (input_mic <= vf_mic_sedang[1])){
        f_mic[1] = (input_mic - vf_mic_sedang[0])/(vf_mic_sedang[1] - vf_mic_sedang[0]);
    }
    else if((input_mic > vf_mic_sedang[1]) && (input_mic <= vf_mic_sedang[2])){
        f_mic[1] = (vf_mic_sedang[2] - input_mic)/(vf_mic_sedang[2] - vf_mic_sedang[1]);
    }
    else if(input_mic > vf_mic_sedang[2]){
        f_mic[1] = 0;
    }

    // fuzzy TINGGI
    if(input_mic <= vf_mic_tinggi[0]){
        f_mic[2] = 0;
    }
    else if((input_mic > vf_mic_tinggi[0]) && (input_mic <= vf_mic_tinggi[1])){
        f_mic[2] = (input_mic - vf_mic_tinggi[0])/(vf_mic_tinggi[1] - vf_mic_tinggi[0]);
    }
    else if(input_mic > vf_mic_tinggi[1]){
        f_mic[2] = 1;
    }
}

static u_int16_t Evaluasi(void){
    unsigned int m,n;
    unsigned int i,idx=0;
    float v_max;

    for(m=0;m<=2;m++){
        for(n=0;n<=2;n++){
            f_rule[3*m + n]=f_accel[m]*f_mic[n];
        }
    }

    v_max = f_rule[0];

    for(i=1;i<RULE_SIZE;i++){
        if(f_rule[i] > v_max){
            v_max = f_rule[i];
            idx = i;
        }
    }

    return idx;
}

static u_int16_t Decision(unsigned int index){
    unsigned int out_fuzzy=0;

    switch (index){
    case 0:
        out_fuzzy = OUT_BIASA; //rendah,sunyi
        break;
    case 1:
        out_fuzzy = OUT_BIASA; //rendah,lumayan
        break;
    case 2:
        out_fuzzy = OUT_BIASA; //rendah,ramai
        break;
    case 3:
        out_fuzzy = OUT_BIASA; //sedang,sunyi
        break;
    case 4:
        out_fuzzy = OUT_AWAS; //sedang,lumayan
        break;
    case 5:
        out_fuzzy = OUT_AWAS; //sedang,ramai
        break;
    case 6:
        out_fuzzy = OUT_AWAS; //tinggi,sunyi
        break;
    case 7:
        out_fuzzy = OUT_AWAS; //tinggi,lumayan
        break;
    case 8:
        out_fuzzy = OUT_JATUH; //tinggi,ramai
        break;
    }

    return out_fuzzy;
}

u_int16_t d_fuzzy(void){
    Accel(ax);
    Mic(adc0);

    return Decision(Evaluasi());
}
