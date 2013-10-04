#ifndef __HTSYSADC_H__
#define __HTSYSADC_H__

// Data types
typedef struct _HTSYS_CHDESC{

}HTSYS_ADC_CHDESC;

typedef struct _HTSYS_ADC_CH{
    unsigned short  chNum;
    unsigned short  rawValue;
    float           physValue;
    HTSYS_CHDESC    *description;
}HTSYS_ADC_CH;

#endif // __HTSYSADC_H__
