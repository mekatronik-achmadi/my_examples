#ifndef MY_FUZZY_H
#define MY_FUZZY_H

#define RULE_SIZE 9

/********************************************/
/* Definisi Fuzzyfikasi Hasil               */
/********************************************/

#define OUT_BIASA 0

#define OUT_AWAS  1

#define OUT_JATUH 2

class MyFuzzy{

    public:
        MyFuzzy();

        void Accel(float input_accel);
        void Mic(unsigned int input_mic);
        unsigned int Evaluasi(void);
        unsigned int Decision(unsigned int index);

        float f_accel[3];
        float f_mic[3];

        float f_rule[RULE_SIZE];

        //variabel fuzzy untuk accel
        double vf_accel_rendah[2] = {17.79, 27.44};
        double vf_accel_sedang[3] = {18.49, 26.94, 31.83};
        double vf_accel_tinggi[2] = {27.44, 31.33};

        //variabel fuzzy untuk mic
        unsigned int vf_mic_rendah[2] = {473, 542};
        unsigned int vf_mic_sedang[3] = {473, 542, 591};
        unsigned int vf_mic_tinggi[2] = {542, 591};

};

#endif // MY_FUZZY_H
