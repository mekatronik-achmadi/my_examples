/**
 * @file    my_fuzzy.h
 * @brief   Akhmad Zainudin fuzzy header
 *
 * @addtogroup Fuzzy
 * @{
 */
#ifndef _MY_FUZZY_H_
#define _MY_FUZZY_H_

/**
 * @brief   Ukuran array rule fuzzy.
 */
#define RULE_SIZE 9

/********************************************/
/* Definisi Fuzzyfikasi Hasil               */
/********************************************/

/**
 * @brief   Fuzzy output status fuzzyfikasi biasa.
 */
#define OUT_BIASA 0

/**
 * @brief   Fuzzy output status fuzzyfikasi awas.
 */
#define OUT_AWAS  1

/**
 * @brief   Fuzzy output status fuzzyfikasi jatuh.
 */
#define OUT_JATUH 2

/**
 * @brief  Class Fuzzy
 */
class MyFuzzy
{
    public:
        MyFuzzy();

        void Accel(double input_accel);
        void Mic(unsigned int input_mic);
        unsigned int Evaluasi(void);

    private:
        unsigned int Decision(unsigned int index);

        //variabel fuzzy untuk accel
        double vf_accel_rendah[2] = {17.79, 27.44};
        double vf_accel_sedang[3] = {18.49, 26.94, 31.83};
        double vf_accel_tinggi[2] = {27.44, 31.33};
        float f_accel[3];

        //variabel fuzzy untuk mic
        unsigned int vf_mic_rendah[2] = {473, 542};
        unsigned int vf_mic_sedang[3] = {473, 542, 591};
        unsigned int vf_mic_tinggi[2] = {542, 591};
        float f_mic[3];

        //variabel fuzzy untuk evaluasi
        float f_rule[RULE_SIZE];
};

#endif
/** @} */
