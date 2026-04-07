# 1 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 363 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c" 2
# 13 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c"
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include\\stdint.h" 1 3
# 20 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include\\stdint.h" 3
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL.h" 1 3
# 17 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL.h" 3
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_ConfDefaults.h" 1 3
# 67 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_ConfDefaults.h" 3
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_Conf.h" 1 3
# 25 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_Conf.h" 3
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_Arm_Conf.h" 1 3
# 744 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_Arm_Conf.h" 3
static __inline__ __attribute__((__always_inline__)) void __SEGGER_RTL_WR_PARTIAL_WORD_func(char *addr, unsigned w, int n) {
  switch (n) {
  default: addr[3] = (-1) > 0 ? w : w >> 24;
  case 3: addr[2] = (-1) > 0 ? w >> 8 : w >> 16;
  case 2: addr[1] = (-1) > 0 ? w >> 16 : w >> 8;
  case 1: addr[0] = (-1) > 0 ? w >> 24 : w;
  case 0: ;
  }
}

static __inline__ __attribute__((__always_inline__)) void __SEGGER_RTL_WR_WORD_func(char *addr, unsigned w) {
  __SEGGER_RTL_WR_PARTIAL_WORD_func(addr, w, 4);
}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_RD_WORD_func(const void *addr) {
  const unsigned char *pAddr = (const unsigned char *)addr;

  return pAddr[0] * ((-1) > 0 ? 0x1000000u : 0x1u) +
         pAddr[1] * ((-1) > 0 ? 0x10000u : 0x100u) +
         pAddr[2] * ((-1) > 0 ? 0x100u : 0x10000u) +
         pAddr[3] * ((-1) > 0 ? 0x1u : 0x1000000u);
}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_BYTE_PATTERN_func(unsigned x) {
  return x * 0x01010101uL;
}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_FILL_HEAD_func(const void *pOrigin, unsigned Word, unsigned Standin) {
  unsigned Mask;
  unsigned Fill;

  (void)pOrigin;

  Fill = __SEGGER_RTL_BYTE_PATTERN_func(Standin);
# 788 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_Arm_Conf.h" 3
  Mask = 0xFFFFFFFFu;
  Mask <<= 8 * (((unsigned)(pOrigin)) & 3u);

  return (Word & Mask) | (Fill & ~Mask);


}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_FILL_TAIL_func(unsigned n, unsigned Word, unsigned Standin) {
  unsigned Mask;
  unsigned Fill;
# 813 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_Arm_Conf.h" 3
  if (n >= 4) {
    return Word;
  } else {
    Fill = __SEGGER_RTL_BYTE_PATTERN_func(Standin);
    Mask = 0xFFFFFFFFu << (8 * n);

    return (Fill & Mask) | (Word & ~Mask);
  }


}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_ZBYTE_CHECK_func(unsigned x) {







  return ((x-0x01010101u) & ~x & 0x80808080u);


}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_DIFF_INDEX_func(unsigned x, unsigned y) {
# 862 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_Arm_Conf.h" 3
  if ((x & 0x000000FFuL) != (y & 0x000000FFuL)) { return 0; }
  if ((x & 0x0000FF00uL) != (y & 0x0000FF00uL)) { return 1; }
  if ((x & 0x00FF0000uL) != (y & 0x00FF0000uL)) { return 2; }
  if ((x & 0xFF000000uL) != (y & 0xFF000000uL)) { return 3; }
  return 4;


}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_DIFF_BYTE_func(unsigned x, int Index) {



  return (x >> (8*Index)) & 0xFF;

}

static __inline__ __attribute__((__always_inline__)) unsigned __SEGGER_RTL_ZBYTE_INDEX_func(unsigned x) {
# 915 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_Arm_Conf.h" 3
  if ((x & 0x000000FFuL) == 0) { return 0; }
  if ((x & 0x0000FF00uL) == 0) { return 1; }
  if ((x & 0x00FF0000uL) == 0) { return 2; }
  if ((x & 0xFF000000uL) == 0) { return 3; }
  return 4;


}

static __inline__ __attribute__((__always_inline__)) _Bool __SEGGER_RTL_atomic_is_lock_free(unsigned size, const volatile void *ptr) {

  switch (size) {
  case 1: return 1;
  case 2: return ((unsigned)ptr & 1) == 0;
  case 4: return ((unsigned)ptr & 3) == 0;
  default: return 0;
  }
}
# 943 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_Arm_Conf.h" 3
extern const int __aeabi_SIGABRT;
extern const int __aeabi_SIGINT;
extern const int __aeabi_SIGILL;
extern const int __aeabi_SIGFPE;
extern const int __aeabi_SIGSEGV;
extern const int __aeabi_SIGTERM;

void __aeabi_SIG_DFL(int sig);
void __aeabi_SIG_IGN(int sig);
void __aeabi_SIG_ERR(int sig);
# 26 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_Conf.h" 2 3
# 68 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL_ConfDefaults.h" 2 3
# 18 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL.h" 2 3
# 38 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL.h" 3
  typedef struct __SEGGER_RTL_FILE_impl __SEGGER_RTL_FILE;


typedef struct __SEGGER_RTL_locale_data_s __SEGGER_RTL_locale_t;
typedef struct __SEGGER_RTL_locale_codeset_s __SEGGER_RTL_locale_codeset_t;

typedef struct {



  const char * decimal_point;
  const char * thousands_sep;
  const char * grouping;

  const char * int_curr_symbol;
  const char * currency_symbol;
  const char * mon_decimal_point;
  const char * mon_thousands_sep;
  const char * mon_grouping;
  const char * positive_sign;
  const char * negative_sign;

  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char int_p_cs_precedes;
  char int_n_cs_precedes;
  char int_p_sep_by_space;
  char int_n_sep_by_space;
  char int_p_sign_posn;
  char int_n_sign_posn;




  const char *day_names;
  const char *abbrev_day_names;
  const char *month_names;
  const char *abbrev_month_names;
  const char *am_pm_indicator;
  const char *date_format;
  const char *time_format;
  const char *date_time_format;
} __SEGGER_RTL_locale_data_t;

struct __SEGGER_RTL_locale_data_s {
  const char * name;
  const __SEGGER_RTL_locale_data_t * data;
  const __SEGGER_RTL_locale_codeset_t * codeset;
};

struct __SEGGER_RTL_POSIX_locale_s {
  const __SEGGER_RTL_locale_t *__category[5];
};

struct timeval;
# 107 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL.h" 3
extern struct __SEGGER_RTL_POSIX_locale_s __SEGGER_RTL_global_locale;
extern struct __SEGGER_RTL_POSIX_locale_s * __SEGGER_RTL_locale_ptr;
extern char * __SEGGER_RTL_locale_name_buffer;
# 118 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL.h" 3
extern const __SEGGER_RTL_locale_t __SEGGER_RTL_c_locale;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_1;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_2;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_3;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_4;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_5;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_6;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_7;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_8;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_9;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_10;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_11;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_13;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_14;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_15;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_iso8859_16;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1250;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1251;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1252;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1253;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1254;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1255;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1256;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1257;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_cp1258;

extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_c_locale_data;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_aa_DJ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_aa_ER_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_aa_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_af_NA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_af_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ak_GH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_am_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_AE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_BH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_DZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_EG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_IQ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_JO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_KW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_LB_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_LY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_MA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_OM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_QA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_SA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_SD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_SY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_TN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ar_YE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_as_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_asa_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_az_Arab_IR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_az_AZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_az_Cyrl_AZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_az_IR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_az_Latn_AZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_be_BY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bem_ZM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bez_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bg_BG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bm_ML_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bn_BD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bn_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bo_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bo_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_br_FR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_brx_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_bs_BA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_byn_ER_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ca_ES_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_cch_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_cgg_UG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_chr_US_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_cs_CZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_cy_GB_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_da_DK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_dav_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_de_AT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_de_BE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_de_CH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_de_DE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_de_LI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_de_LU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_dv_MV_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_dz_BT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ebu_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ee_GH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ee_TG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_el_CY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_el_GR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_AS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_AU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_BE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_BW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_BZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_CA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_Dsrt_US_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_GB_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_GU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_HK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_IE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_JM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_MH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_MP_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_MT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_MU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_NA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_NZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_PH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_PK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_SG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_TT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_UM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_US_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_US_POSIX_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_VI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_ZW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_en_ZZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_AR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_BO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_CL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_CO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_CR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_DO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_EC_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_ES_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_GQ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_GT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_HN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_MX_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_NI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_PA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_PE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_PR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_PY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_SV_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_US_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_UY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_es_VE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_et_EE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_eu_ES_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fa_AF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fa_IR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ff_SN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fi_FI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fil_PH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fo_FO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_BE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_BF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_BI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_BJ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_BL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_CM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_DJ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_FR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_GA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_GN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_GP_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_GQ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_KM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_LU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_MC_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_MF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_MG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_ML_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_MQ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_NE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_RE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_RW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_SN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_TD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fr_TG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_fur_IT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ga_IE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gaa_GH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gez_ER_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gez_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gl_ES_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gsw_CH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gu_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_guz_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_gv_GB_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_Arab_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_Arab_SD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_GH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_Latn_GH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_Latn_NE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_Latn_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_NE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ha_SD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_haw_US_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_he_IL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_hi_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_hr_HR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_hu_HU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_hy_AM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_id_ID_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ig_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ii_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_is_IS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_it_CH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_it_IT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ja_JP_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_jmc_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ka_GE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kab_DZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kaj_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kam_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kcg_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kde_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kea_CV_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kfo_CI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_khq_ML_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ki_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kk_Cyrl_KZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kk_KZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kl_GL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kln_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_km_KH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kn_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ko_KR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kok_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kpe_GN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kpe_LR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ksb_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ksh_DE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_Arab_IQ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_Arab_IR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_IQ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_IR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_Latn_SY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_Latn_TR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_SY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ku_TR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_kw_GB_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ky_KG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_lag_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_lg_UG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ln_CD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ln_CG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_lo_LA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_lt_LT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_luo_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_luy_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_lv_LV_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mas_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mas_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mer_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mfe_MU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mg_MG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mi_NZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mk_MK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ml_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mn_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mn_Cyrl_MN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mn_MN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mn_Mong_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mr_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ms_BN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ms_MY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_mt_MT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_my_MM_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_naq_NA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nb_NO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nd_ZW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nds_DE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ne_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ne_NP_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nl_BE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nl_NL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nn_NO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nr_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nso_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ny_MW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_nyn_UG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_oc_FR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_om_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_om_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_or_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pa_Arab_PK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pa_Guru_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pa_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pa_PK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pl_PL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ps_AF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pt_AO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pt_BR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pt_GW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pt_MZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_pt_PT_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_rm_CH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ro_MD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ro_RO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_rof_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ru_MD_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ru_RU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ru_UA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_rw_RW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_rwk_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sa_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_saq_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_se_FI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_se_NO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_seh_MZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ses_ML_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sg_CF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sh_BA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sh_CS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sh_YU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_shi_Latn_MA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_shi_MA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_shi_Tfng_MA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_si_LK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sid_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sk_SK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sl_SI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sn_ZW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_so_DJ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_so_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_so_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_so_SO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sq_AL_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_BA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_CS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Cyrl_BA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Cyrl_CS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Cyrl_ME_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Cyrl_RS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Cyrl_YU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Latn_BA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Latn_CS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Latn_ME_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Latn_RS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_Latn_YU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_ME_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_RS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sr_YU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ss_SZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ss_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ssy_ER_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_st_LS_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_st_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sv_FI_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sv_SE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sw_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_sw_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_syr_SY_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ta_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ta_LK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_te_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_teo_KE_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_teo_UG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tg_Cyrl_TJ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tg_TJ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_th_TH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ti_ER_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ti_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tig_ER_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tl_PH_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tn_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_to_TO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tr_TR_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_trv_TW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ts_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tt_RU_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tzm_Latn_MA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_tzm_MA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ug_Arab_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ug_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_uk_UA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ur_IN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ur_PK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_uz_AF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_uz_Arab_AF_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_uz_Cyrl_UZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_uz_Latn_UZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_uz_UZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_ve_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_vi_VN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_vun_TZ_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_wal_ET_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_wo_Latn_SN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_wo_SN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_xh_ZA_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_xog_UG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_yo_NG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hans_CN_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hans_HK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hans_MO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hans_SG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hant_HK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hant_MO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_Hant_TW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_HK_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_MO_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_SG_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zh_TW_locale;
extern const __SEGGER_RTL_locale_data_t __SEGGER_RTL_zu_ZA_locale;

extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_ascii;
extern const __SEGGER_RTL_locale_codeset_t __SEGGER_RTL_codeset_utf8;

extern const char __SEGGER_RTL_data_utf8_period [];
extern const char __SEGGER_RTL_data_utf8_comma [];
extern const char __SEGGER_RTL_data_utf8_space [];
extern const char __SEGGER_RTL_data_utf8_plus [];
extern const char __SEGGER_RTL_data_utf8_minus [];
extern const char __SEGGER_RTL_data_empty_string[];
# 546 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL.h" 3
int __SEGGER_RTL_X_set_time_of_day (const struct timeval *__tp);
int __SEGGER_RTL_X_get_time_of_day (struct timeval *__tp);
const __SEGGER_RTL_locale_t * __SEGGER_RTL_X_find_locale (const char *__locale);
__SEGGER_RTL_FILE * __SEGGER_RTL_X_file_open (const char *__filename, const char *__mode);
int __SEGGER_RTL_X_file_stat (__SEGGER_RTL_FILE *__stream);
int __SEGGER_RTL_X_file_read (__SEGGER_RTL_FILE *__stream, char *__s, unsigned __len);
int __SEGGER_RTL_X_file_write (__SEGGER_RTL_FILE *__stream, const char *__s, unsigned __len);
int __SEGGER_RTL_X_file_unget (__SEGGER_RTL_FILE *__stream, int __c);
int __SEGGER_RTL_X_file_close (__SEGGER_RTL_FILE *__stream);
int __SEGGER_RTL_X_file_error (__SEGGER_RTL_FILE *__stream);
int __SEGGER_RTL_X_file_flush (__SEGGER_RTL_FILE *__stream);
int __SEGGER_RTL_X_file_eof (__SEGGER_RTL_FILE *__stream);
void __SEGGER_RTL_X_file_clrerr (__SEGGER_RTL_FILE *__stream);
int __SEGGER_RTL_X_file_seek (__SEGGER_RTL_FILE *__stream, long __offset, int __whence);
int __SEGGER_RTL_X_file_getpos (__SEGGER_RTL_FILE *__stream, long *__pos);
int __SEGGER_RTL_X_file_bufsize (__SEGGER_RTL_FILE *__stream);
__SEGGER_RTL_FILE * __SEGGER_RTL_X_file_tmpfile (void);
char * __SEGGER_RTL_X_file_tmpnam (char *__s, unsigned __max);
int __SEGGER_RTL_X_file_remove (const char *__filename);
int __SEGGER_RTL_X_file_rename (const char *__old, const char *__new);
void __attribute__((__weak__)) __SEGGER_RTL_X_heap_lock (void);
void __attribute__((__weak__)) __SEGGER_RTL_X_heap_unlock (void);
int __attribute__((__weak__)) __SEGGER_RTL_X_atomic_lock (void);
void __attribute__((__weak__)) __SEGGER_RTL_X_atomic_unlock (int __state);
int __attribute__((__weak__)) __SEGGER_RTL_X_atomic_is_lock_free (unsigned int __size, void *__ptr);
void __attribute__((__weak__)) __SEGGER_RTL_X_atomic_synchronize (void);
volatile int * __aeabi_errno_addr (void);
void __aeabi_assert (const char *__expression, const char *__filename, int __line);
# 583 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include/__SEGGER_RTL.h" 3
void __SEGGER_RTL_execute_at_exit_fns (void);
void __SEGGER_RTL_set_locale_name_buffer (char *__buffer);
int __SEGGER_RTL_mb_max (const struct __SEGGER_RTL_POSIX_locale_s *__loc);
int __SEGGER_RTL_mb_cur_max (void);
void __SEGGER_RTL_init_heap (void *__ptr, unsigned int __size);
# 21 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include\\stdint.h" 2 3
# 272 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include\\stdint.h" 3
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long long int int64_t;
typedef long long unsigned int uint64_t;

typedef signed char int_least8_t;
typedef short int_least16_t;
typedef int int_least32_t;
typedef long long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short uint_least16_t;
typedef unsigned int uint_least32_t;
typedef long long unsigned int uint_least64_t;

typedef signed char int_fast8_t;
typedef short int_fast16_t;
typedef int int_fast32_t;
typedef long long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned short uint_fast16_t;
typedef unsigned int uint_fast32_t;
typedef long long unsigned int uint_fast64_t;

typedef int intptr_t;
typedef unsigned int uintptr_t;

typedef long long int intmax_t;
typedef long long unsigned int uintmax_t;
# 14 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c" 2
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include\\stdio.h" 1 3
# 72 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include\\stdio.h" 3
typedef unsigned int size_t;




typedef long fpos_t;




typedef struct __SEGGER_RTL_FILE_impl FILE;




typedef struct __SEGGER_RTL_POSIX_locale_s *locale_t;
# 97 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include\\stdio.h" 3
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
# 108 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include\\stdio.h" 3
int putchar (int __c);
int getchar (void);
int puts (const char *__s);
char * gets (char *__s);
int sprintf (char *__s, const char *__format, ...);
int sprintf_l (char *__s, locale_t __loc, const char *__format, ...);
int snprintf (char *__s, size_t __n, const char *__format, ...);
int snprintf_l (char *__s, size_t __n, locale_t __loc, const char *__format, ...);
int vsnprintf (char *__s, size_t __n, const char *__format, __builtin_va_list __arg);
int vsnprintf_l (char *__s, size_t __n, locale_t __loc, const char *__format, __builtin_va_list __arg);
int printf (const char *__format, ...);
int printf_l (locale_t __loc, const char *__format, ...);
int vprintf (const char *__format, __builtin_va_list __arg);
int vprintf_l (locale_t __loc, const char *__format, __builtin_va_list __arg);
int vsprintf (char *__s, const char *__format, __builtin_va_list __arg);
int vsprintf_l (char *__s, locale_t __loc, const char *__format, __builtin_va_list __arg);
int vasprintf (char **__strp, const char *__format, __builtin_va_list __ap);
int vasprintf_l (char **__strp, locale_t __loc, const char *__format, __builtin_va_list __ap);
int asprintf (char **__strp, const char *__format, ...);
int asprintf_l (char **__strp, locale_t __loc, const char *__format, ...);

int scanf (const char *__format, ...);
int scanf_l (locale_t __loc, const char *__format, ...);
int sscanf (const char *__s, const char *__format, ...);
int sscanf_l (const char *__s, locale_t __loc, const char *__format, ...);
int vscanf (const char *__format, __builtin_va_list __arg);
int vscanf_l (locale_t __loc, const char *__format, __builtin_va_list __arg);
int vsscanf (const char *__s, const char *__format, __builtin_va_list __arg);
int vsscanf_l (const char *__s, locale_t __loc, const char *__format, __builtin_va_list __arg);

void clearerr (FILE *);
int fclose (FILE *);
int feof (FILE *);
int ferror (FILE *);
int fflush (FILE *);
int fgetc (FILE *);
int fgetpos (FILE *, fpos_t *);
char * fgets (char *, int, FILE *);
int fileno (FILE *);
FILE * fopen (const char *, const char *);
int fprintf (FILE *, const char *, ...);
int fprintf_l (FILE *, locale_t, const char *, ...);
int vfprintf (FILE *__stream, const char *__format, __builtin_va_list __arg);
int vfprintf_l (FILE *__stream, locale_t loc, const char *__format, __builtin_va_list __arg);
int fputc (int, FILE *);
int fputs (const char *, FILE *);
size_t fread (void *, size_t, size_t, FILE *);
FILE * freopen (const char *, const char *, FILE *);
int fscanf (FILE *, const char *, ...);
int fscanf_l (FILE *, locale_t, const char *, ...);
int vfscanf (FILE *, const char *, __builtin_va_list);
int vfscanf_l (FILE *, locale_t, const char *, __builtin_va_list);
int fseek (FILE *, long, int);
int fsetpos (FILE *, const fpos_t *);
long ftell (FILE *);
size_t fwrite (const void *, size_t, size_t, FILE *);
int getc (FILE *);
void perror (const char *);
int putc (int, FILE *);
int remove (const char *);
int rename (const char *, const char *);
void rewind (FILE *);
void setbuf (FILE *, char *);
int setvbuf (FILE *, char *, int, size_t);
FILE * tmpfile (void);
char * tmpnam (char *);
int ungetc (int, FILE *);





int dprintf (int, const char *, ...);
int vdprintf (int, const char *, __builtin_va_list);
FILE * fdopen (int, const char *);
# 15 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c" 2
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include\\string.h" 1 3
# 56 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 7.32a/include\\string.h" 3
void * (memcpy) (void *__s1, const void *__s2, size_t __n);
void * (memccpy) (void *__s1, const void *__s2, int __c, size_t __n);
void * (mempcpy) (void *__s1, const void *__s2, size_t __n);
void * (memmove) (void *__s1, const void *__s2, size_t __n);
int (memcmp) (const void *__s1, const void *__s2, size_t __n);
size_t (memlcp) (const void *__s1, const void *__s2, size_t __n);
void * (memchr) (const void *__s, int __c, size_t __n);
void * (memrchr) (const void *__s, int __c, size_t __n);
void * (memmem) (const void *__s1, size_t __n1, const void *__s2, size_t __n2);
void * (memset) (void *__s, int __c, size_t __n);
char * (strcpy) (char *__s1, const char *__s2);
char * (stpcpy) (char *__s1, const char *__s2);
char * (strncpy) (char *__s1, const char *__s2, size_t __n);
char * (stpncpy) (char *__s1, const char *__s2, size_t __n);
size_t (strlcpy) (char *__s1, const char *__s2, size_t __n);
char * (strcat) (char *__s1, const char *__s2);
char * (strncat) (char *__s1, const char *__s2, size_t __n);
size_t (strlcat) (char *__s1, const char *__s2, size_t __n);
int (strcmp) (const char *__s1, const char *__s2);
int (strncmp) (const char *__s1, const char *__s2, size_t __n);
int (strcasecmp) (const char *__s1, const char *__s2);
int (strncasecmp) (const char *__s1, const char *__s2, size_t __n);
int (strcoll) (const char *__s1, const char *__s2);
char * (strchr) (const char *__s, int __c);
char * (strnchr) (const char *__str, size_t __n, int __ch);
size_t (strcspn) (const char *__s1, const char *__s2);
char * (strpbrk) (const char *__s1, const char *__s2);
char * (strrchr) (const char *__s, int __c);
size_t (strspn) (const char *__s1, const char *__s2);
char * (strstr) (const char *__s1, const char *__s2);
char * (strnstr) (const char *__s1, const char *__s2, size_t __n);
char * (strcasestr) (const char *__s1, const char *__s2);
char * (strncasestr) (const char *__s1, const char *__s2, size_t __n);
size_t (strlen) (const char *__s);
size_t (strnlen) (const char *__s, size_t __n);
size_t (strxfrm) (char *__s1, const char *__s2, size_t __n);
char * (strtok) (char *__s1, const char *__s2);
char * (strtok_r) (char *__s1, const char *__s2, char **__s3);
char * (strsep) (char **__stringp, const char *__delim);
char * (strdup) (const char *__s1);
char * (strndup) (const char *__s1, size_t __n);
char * (strerror) (int __num);

int (ffs) (int __i);
int (ffsl) (long __i);
int (ffsll) (long long __i);
# 16 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c" 2
# 1 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include\\stm32g0b1xx.h" 1
# 68 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include\\stm32g0b1xx.h"
typedef enum
{

  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  SVC_IRQn = -5,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,

  WWDG_IRQn = 0,
  PVD_VDDIO2_IRQn = 1,
  RTC_TAMP_IRQn = 2,
  FLASH_IRQn = 3,
  RCC_CRS_IRQn = 4,
  EXTI0_1_IRQn = 5,
  EXTI2_3_IRQn = 6,
  EXTI4_15_IRQn = 7,
  USB_UCPD1_2_IRQn = 8,
  DMA1_Channel1_IRQn = 9,
  DMA1_Channel2_3_IRQn = 10,
  DMA1_Ch4_7_DMA2_Ch1_5_DMAMUX1_OVR_IRQn = 11,
  ADC1_COMP_IRQn = 12,
  TIM1_BRK_UP_TRG_COM_IRQn = 13,
  TIM1_CC_IRQn = 14,
  TIM2_IRQn = 15,
  TIM3_TIM4_IRQn = 16,
  TIM6_DAC_LPTIM1_IRQn = 17,
  TIM7_LPTIM2_IRQn = 18,
  TIM14_IRQn = 19,
  TIM15_IRQn = 20,
  TIM16_FDCAN_IT0_IRQn = 21,
  TIM17_FDCAN_IT1_IRQn = 22,
  I2C1_IRQn = 23,
  I2C2_3_IRQn = 24,
  SPI1_IRQn = 25,
  SPI2_3_IRQn = 26,
  USART1_IRQn = 27,
  USART2_LPUART2_IRQn = 28,
  USART3_4_5_6_LPUART1_IRQn = 29,
  CEC_IRQn = 30,
} IRQn_Type;





# 1 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 1
# 29 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
# 63 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
# 1 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_version.h" 1 3
# 29 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_version.h" 3
# 64 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 2 3
# 115 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
# 1 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_compiler.h" 1 3
# 54 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_compiler.h" 3
# 1 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 1 3
# 29 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wunused-parameter"
# 71 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed)) T_UINT32 { uint32_t v; };
#pragma GCC diagnostic pop



#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT16_WRITE { uint16_t v; };
#pragma GCC diagnostic pop



#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT16_READ { uint16_t v; };
#pragma GCC diagnostic pop



#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT32_WRITE { uint32_t v; };
#pragma GCC diagnostic pop



#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
  struct __attribute__((packed, aligned(1))) T_UINT32_READ { uint32_t v; };
#pragma GCC diagnostic pop
# 131 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline __attribute__((__noreturn__)) void __cmsis_start(void)
{
  extern void _start(void) __attribute__((__noreturn__));

  typedef struct {
    uint32_t const* src;
    uint32_t* dest;
    uint32_t wlen;
  } __copy_table_t;

  typedef struct {
    uint32_t* dest;
    uint32_t wlen;
  } __zero_table_t;

  extern const __copy_table_t __copy_table_start__;
  extern const __copy_table_t __copy_table_end__;
  extern const __zero_table_t __zero_table_start__;
  extern const __zero_table_t __zero_table_end__;

  for (__copy_table_t const* pTable = &__copy_table_start__; pTable < &__copy_table_end__; ++pTable) {
    for(uint32_t i=0u; i<pTable->wlen; ++i) {
      pTable->dest[i] = pTable->src[i];
    }
  }

  for (__zero_table_t const* pTable = &__zero_table_start__; pTable < &__zero_table_end__; ++pTable) {
    for(uint32_t i=0u; i<pTable->wlen; ++i) {
      pTable->dest[i] = 0u;
    }
  }

  _start();
}
# 258 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __ISB(void)
{
  __asm volatile ("isb 0xF":::"memory");
}







__attribute__((always_inline)) static inline void __DSB(void)
{
  __asm volatile ("dsb 0xF":::"memory");
}







__attribute__((always_inline)) static inline void __DMB(void)
{
  __asm volatile ("dmb 0xF":::"memory");
}
# 292 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __REV(uint32_t value)
{



  uint32_t result;

  __asm ("rev %0, %1" : "=l" (result) : "l" (value) );
  return result;

}
# 311 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __REV16(uint32_t value)
{
  uint32_t result;

  __asm ("rev16 %0, %1" : "=l" (result) : "l" (value) );
  return result;
}
# 326 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline int16_t __REVSH(int16_t value)
{



  int16_t result;

  __asm ("revsh %0, %1" : "=l" (result) : "l" (value) );
  return result;

}
# 346 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  op2 %= 32U;
  if (op2 == 0U)
  {
    return op1;
  }
  return (op1 >> op2) | (op1 << (32U - op2));
}
# 373 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;






  uint32_t s = (4U * 8U) - 1U;

  result = value;
  for (value >>= 1U; value != 0U; value >>= 1U)
  {
    result <<= 1U;
    result |= value & 1U;
    s--;
  }
  result <<= s;

  return result;
}
# 403 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint8_t __CLZ(uint32_t value)
{
# 414 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
  if (value == 0U)
  {
    return 32U;
  }
  return __builtin_clz(value);
}
# 707 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline int32_t __SSAT(int32_t val, uint32_t sat)
{
  if ((sat >= 1U) && (sat <= 32U))
  {
    const int32_t max = (int32_t)((1U << (sat - 1U)) - 1U);
    const int32_t min = -1 - max ;
    if (val > max)
    {
      return max;
    }
    else if (val < min)
    {
      return min;
    }
  }
  return val;
}
# 732 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __USAT(int32_t val, uint32_t sat)
{
  if (sat <= 31U)
  {
    const uint32_t max = ((1U << sat) - 1U);
    if (val > (int32_t)max)
    {
      return max;
    }
    else if (val < 0)
    {
      return 0U;
    }
  }
  return (uint32_t)val;
}
# 949 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __enable_irq(void)
{
  __asm volatile ("cpsie i" : : : "memory");
}







__attribute__((always_inline)) static inline void __disable_irq(void)
{
  __asm volatile ("cpsid i" : : : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_CONTROL(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}
# 1001 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __set_CONTROL(uint32_t control)
{
  __asm volatile ("MSR control, %0" : : "r" (control) : "memory");
  __ISB();
}
# 1027 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __get_IPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, ipsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_APSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, apsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_xPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, xpsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_PSP(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, psp" : "=r" (result) );
  return(result);
}
# 1099 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __set_PSP(uint32_t topOfProcStack)
{
  __asm volatile ("MSR psp, %0" : : "r" (topOfProcStack) : );
}
# 1123 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __get_MSP(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, msp" : "=r" (result) );
  return(result);
}
# 1153 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __set_MSP(uint32_t topOfMainStack)
{
  __asm volatile ("MSR msp, %0" : : "r" (topOfMainStack) : );
}
# 1204 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __get_PRIMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, primask" : "=r" (result) );
  return(result);
}
# 1234 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline void __set_PRIMASK(uint32_t priMask)
{
  __asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}
# 1588 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
__attribute__((always_inline)) static inline uint32_t __get_FPSCR(void)
{
# 1604 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
  return(0U);

}







__attribute__((always_inline)) static inline void __set_FPSCR(uint32_t fpscr)
{
# 1627 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
  (void)fpscr;

}
# 2209 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_gcc.h" 3
#pragma GCC diagnostic pop
# 55 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/cmsis_compiler.h" 2 3
# 116 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 2 3
# 210 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
typedef union
{
  struct
  {
    uint32_t _reserved0:28;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} APSR_Type;
# 240 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:23;
  } b;
  uint32_t w;
} IPSR_Type;
# 258 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:15;
    uint32_t T:1;
    uint32_t _reserved1:3;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} xPSR_Type;
# 297 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
typedef union
{
  struct
  {
    uint32_t nPRIV:1;
    uint32_t SPSEL:1;
    uint32_t _reserved1:30;
  } b;
  uint32_t w;
} CONTROL_Type;
# 328 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
typedef struct
{
  volatile uint32_t ISER[1U];
        uint32_t RESERVED0[31U];
  volatile uint32_t ICER[1U];
        uint32_t RESERVED1[31U];
  volatile uint32_t ISPR[1U];
        uint32_t RESERVED2[31U];
  volatile uint32_t ICPR[1U];
        uint32_t RESERVED3[31U];
        uint32_t RESERVED4[64U];
  volatile uint32_t IP[8U];
} NVIC_Type;
# 355 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
typedef struct
{
  volatile const uint32_t CPUID;
  volatile uint32_t ICSR;

  volatile uint32_t VTOR;



  volatile uint32_t AIRCR;
  volatile uint32_t SCR;
  volatile uint32_t CCR;
        uint32_t RESERVED1;
  volatile uint32_t SHP[2U];
  volatile uint32_t SHCSR;
} SCB_Type;
# 472 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
typedef struct
{
  volatile uint32_t CTRL;
  volatile uint32_t LOAD;
  volatile uint32_t VAL;
  volatile const uint32_t CALIB;
} SysTick_Type;
# 524 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
typedef struct
{
  volatile const uint32_t TYPE;
  volatile uint32_t CTRL;
  volatile uint32_t RNR;
  volatile uint32_t RBAR;
  volatile uint32_t RASR;
} MPU_Type;
# 741 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    __asm volatile("":::"memory");
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[0U] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    __asm volatile("":::"memory");
  }
}
# 760 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[0U] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
# 779 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[0U] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    __DSB();
    __ISB();
  }
}
# 798 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}
# 817 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}
# 832 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[0U] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}
# 850 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )] = ((uint32_t)(((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )] & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
       (((priority << (8U - 2U)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] = ((uint32_t)(((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
       (((priority << (8U - 2U)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
  }
}
# 874 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[ ( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL) ) & (uint32_t)0xFFUL) >> (8U - 2U)));
  }
  else
  {
    return((uint32_t)(((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL) ) & (uint32_t)0xFFUL) >> (8U - 2U)));
  }
}
# 899 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(2U)) ? (uint32_t)(2U) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits = ((PriorityGroupTmp + (uint32_t)(2U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(2U));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority & (uint32_t)((1UL << (SubPriorityBits )) - 1UL)))
         );
}
# 926 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(2U)) ? (uint32_t)(2U) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits = ((PriorityGroupTmp + (uint32_t)(2U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(2U));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority = (Priority ) & (uint32_t)((1UL << (SubPriorityBits )) - 1UL);
}
# 950 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{

  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  vectors[(int32_t)IRQn + 16] = vector;





}
# 971 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{

  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  return vectors[(int32_t)IRQn + 16];




}






__attribute__((__noreturn__)) static inline void __NVIC_SystemReset(void)
{
  __DSB();

  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR = ((0x5FAUL << 16U) |
                 (1UL << 2U));
  __DSB();

  for(;;)
  {
    __asm volatile ("nop");
  }
}







# 1 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/mpu_armv7.h" 1 3
# 29 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/mpu_armv7.h" 3
# 183 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include/mpu_armv7.h" 3
typedef struct {
  uint32_t RBAR;
  uint32_t RASR;
} ARM_MPU_Region_t;




static inline void ARM_MPU_Enable(uint32_t MPU_Control)
{
  __DMB();
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->CTRL = MPU_Control | (1UL );



  __DSB();
  __ISB();
}



static inline void ARM_MPU_Disable(void)
{
  __DMB();



  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->CTRL &= ~(1UL );
  __DSB();
  __ISB();
}




static inline void ARM_MPU_ClrRegion(uint32_t rnr)
{
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RNR = rnr;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RASR = 0U;
}





static inline void ARM_MPU_SetRegion(uint32_t rbar, uint32_t rasr)
{
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR = rbar;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RASR = rasr;
}






static inline void ARM_MPU_SetRegionEx(uint32_t rnr, uint32_t rbar, uint32_t rasr)
{
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RNR = rnr;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR = rbar;
  ((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RASR = rasr;
}






static inline void ARM_MPU_OrderedMemcpy(volatile uint32_t* dst, const uint32_t* __restrict src, uint32_t len)
{
  uint32_t i;
  for (i = 0U; i < len; ++i)
  {
    dst[i] = src[i];
  }
}





static inline void ARM_MPU_Load(ARM_MPU_Region_t const* table, uint32_t cnt)
{
  const uint32_t rowWordSize = sizeof(ARM_MPU_Region_t)/4U;
  while (cnt > 1U) {
    ARM_MPU_OrderedMemcpy(&(((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR), &(table->RBAR), 1U*rowWordSize);
    table += 1U;
    cnt -= 1U;
  }
  ARM_MPU_OrderedMemcpy(&(((MPU_Type *) ((0xE000E000UL) + 0x0D90UL) )->RBAR), &(table->RBAR), cnt*rowWordSize);
}
# 1008 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 2 3
# 1027 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline uint32_t SCB_GetFPUType(void)
{
    return 0U;
}
# 1058 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
static inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = (uint32_t)(ticks - 1UL);
  __NVIC_SetPriority (SysTick_IRQn, (1UL << 2U) - 1UL);
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL = 0UL;
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = (1UL << 2U) |
                   (1UL << 1U) |
                   (1UL );
  return (0UL);
}
# 115 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include\\stm32g0b1xx.h" 2
# 1 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include/system_stm32g0xx.h" 1
# 56 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include/system_stm32g0xx.h"
extern uint32_t SystemCoreClock;

extern const uint32_t AHBPrescTable[16];
extern const uint32_t APBPrescTable[8];
# 85 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include/system_stm32g0xx.h"
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
# 116 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include\\stm32g0b1xx.h" 2
# 125 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include\\stm32g0b1xx.h"
typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IER;
  volatile uint32_t CR;
  volatile uint32_t CFGR1;
  volatile uint32_t CFGR2;
  volatile uint32_t SMPR;
       uint32_t RESERVED1;
       uint32_t RESERVED2;
  volatile uint32_t TR1;
  volatile uint32_t TR2;
  volatile uint32_t CHSELR;
  volatile uint32_t TR3;
       uint32_t RESERVED3[4];
  volatile uint32_t DR;
       uint32_t RESERVED4[23];
  volatile uint32_t AWD2CR;
  volatile uint32_t AWD3CR;
       uint32_t RESERVED5[3];
  volatile uint32_t CALFACT;
} ADC_TypeDef;

typedef struct
{
  volatile uint32_t CCR;
} ADC_Common_TypeDef;





typedef struct
{
  volatile uint32_t CREL;
  volatile uint32_t ENDN;
       uint32_t RESERVED1;
  volatile uint32_t DBTP;
  volatile uint32_t TEST;
  volatile uint32_t RWD;
  volatile uint32_t CCCR;
  volatile uint32_t NBTP;
  volatile uint32_t TSCC;
  volatile uint32_t TSCV;
  volatile uint32_t TOCC;
  volatile uint32_t TOCV;
       uint32_t RESERVED2[4];
  volatile uint32_t ECR;
  volatile uint32_t PSR;
  volatile uint32_t TDCR;
       uint32_t RESERVED3;
  volatile uint32_t IR;
  volatile uint32_t IE;
  volatile uint32_t ILS;
  volatile uint32_t ILE;
       uint32_t RESERVED4[8];
  volatile uint32_t RXGFC;
  volatile uint32_t XIDAM;
  volatile uint32_t HPMS;
       uint32_t RESERVED5;
  volatile uint32_t RXF0S;
  volatile uint32_t RXF0A;
  volatile uint32_t RXF1S;
  volatile uint32_t RXF1A;
       uint32_t RESERVED6[8];
  volatile uint32_t TXBC;
  volatile uint32_t TXFQS;
  volatile uint32_t TXBRP;
  volatile uint32_t TXBAR;
  volatile uint32_t TXBCR;
  volatile uint32_t TXBTO;
  volatile uint32_t TXBCF;
  volatile uint32_t TXBTIE;
  volatile uint32_t TXBCIE;
  volatile uint32_t TXEFS;
  volatile uint32_t TXEFA;
} FDCAN_GlobalTypeDef;





typedef struct
{
  volatile uint32_t CKDIV;
} FDCAN_Config_TypeDef;




typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t TXDR;
  volatile uint32_t RXDR;
  volatile uint32_t ISR;
  volatile uint32_t IER;
}CEC_TypeDef;




typedef struct
{
  volatile uint32_t CSR;
} COMP_TypeDef;

typedef struct
{
  volatile uint32_t CSR_ODD;
  volatile uint32_t CSR_EVEN;
} COMP_Common_TypeDef;




typedef struct
{
  volatile uint32_t DR;
  volatile uint32_t IDR;
  volatile uint32_t CR;
       uint32_t RESERVED1;
  volatile uint32_t INIT;
  volatile uint32_t POL;
} CRC_TypeDef;




typedef struct
{
volatile uint32_t CR;
volatile uint32_t CFGR;
volatile uint32_t ISR;
volatile uint32_t ICR;
} CRS_TypeDef;



typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SWTRIGR;
  volatile uint32_t DHR12R1;
  volatile uint32_t DHR12L1;
  volatile uint32_t DHR8R1;
  volatile uint32_t DHR12R2;
  volatile uint32_t DHR12L2;
  volatile uint32_t DHR8R2;
  volatile uint32_t DHR12RD;
  volatile uint32_t DHR12LD;
  volatile uint32_t DHR8RD;
  volatile uint32_t DOR1;
  volatile uint32_t DOR2;
  volatile uint32_t SR;
  volatile uint32_t CCR;
  volatile uint32_t MCR;
  volatile uint32_t SHSR1;
  volatile uint32_t SHSR2;
  volatile uint32_t SHHR;
  volatile uint32_t SHRR;
} DAC_TypeDef;




typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;
  volatile uint32_t APBFZ1;
  volatile uint32_t APBFZ2;
} DBG_TypeDef;




typedef struct
{
  volatile uint32_t CCR;
  volatile uint32_t CNDTR;
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
} DMA_TypeDef;




typedef struct
{
  volatile uint32_t CCR;
}DMAMUX_Channel_TypeDef;

typedef struct
{
  volatile uint32_t CSR;
  volatile uint32_t CFR;
}DMAMUX_ChannelStatus_TypeDef;

typedef struct
{
  volatile uint32_t RGCR;
}DMAMUX_RequestGen_TypeDef;

typedef struct
{
  volatile uint32_t RGSR;
  volatile uint32_t RGCFR;
}DMAMUX_RequestGenStatus_TypeDef;




typedef struct
{
  volatile uint32_t RTSR1;
  volatile uint32_t FTSR1;
  volatile uint32_t SWIER1;
  volatile uint32_t RPR1;
  volatile uint32_t FPR1;
       uint32_t RESERVED1[3];
  volatile uint32_t RTSR2;
  volatile uint32_t FTSR2;
  volatile uint32_t SWIER2;
  volatile uint32_t RPR2;
  volatile uint32_t FPR2;
       uint32_t RESERVED3[11];
  volatile uint32_t EXTICR[4];
       uint32_t RESERVED4[4];
  volatile uint32_t IMR1;
  volatile uint32_t EMR1;
       uint32_t RESERVED5[2];
  volatile uint32_t IMR2;
  volatile uint32_t EMR2;
} EXTI_TypeDef;




typedef struct
{
  volatile uint32_t ACR;
       uint32_t RESERVED1;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t ECCR;
  volatile uint32_t ECC2R;
  volatile uint32_t OPTR;
  volatile uint32_t PCROP1ASR;
  volatile uint32_t PCROP1AER;
  volatile uint32_t WRP1AR;
  volatile uint32_t WRP1BR;
  volatile uint32_t PCROP1BSR;
  volatile uint32_t PCROP1BER;
       uint32_t RESERVED5[2];
  volatile uint32_t PCROP2ASR;
  volatile uint32_t PCROP2AER;
  volatile uint32_t WRP2AR;
  volatile uint32_t WRP2BR;
  volatile uint32_t PCROP2BSR;
  volatile uint32_t PCROP2BER;
       uint32_t RESERVED7[9];
  volatile uint32_t SECR;
} FLASH_TypeDef;




typedef struct
{
  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFR[2];
  volatile uint32_t BRR;
} GPIO_TypeDef;





typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t OAR1;
  volatile uint32_t OAR2;
  volatile uint32_t TIMINGR;
  volatile uint32_t TIMEOUTR;
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t PECR;
  volatile uint32_t RXDR;
  volatile uint32_t TXDR;
} I2C_TypeDef;




typedef struct
{
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
  volatile uint32_t WINR;
} IWDG_TypeDef;




typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t IER;
  volatile uint32_t CFGR;
  volatile uint32_t CR;
  volatile uint32_t CMP;
  volatile uint32_t ARR;
  volatile uint32_t CNT;
  volatile uint32_t RESERVED1;
  volatile uint32_t CFGR2;
} LPTIM_TypeDef;





typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t CR3;
  volatile uint32_t CR4;
  volatile uint32_t SR1;
  volatile uint32_t SR2;
  volatile uint32_t SCR;
       uint32_t RESERVED1;
  volatile uint32_t PUCRA;
  volatile uint32_t PDCRA;
  volatile uint32_t PUCRB;
  volatile uint32_t PDCRB;
  volatile uint32_t PUCRC;
  volatile uint32_t PDCRC;
  volatile uint32_t PUCRD;
  volatile uint32_t PDCRD;
  volatile uint32_t PUCRE;
  volatile uint32_t PDCRE;
  volatile uint32_t PUCRF;
  volatile uint32_t PDCRF;
} PWR_TypeDef;




typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t ICSCR;
  volatile uint32_t CFGR;
  volatile uint32_t PLLCFGR;
  volatile uint32_t RESERVED0;
  volatile uint32_t CRRCR;
  volatile uint32_t CIER;
  volatile uint32_t CIFR;
  volatile uint32_t CICR;
  volatile uint32_t IOPRSTR;
  volatile uint32_t AHBRSTR;
  volatile uint32_t APBRSTR1;
  volatile uint32_t APBRSTR2;
  volatile uint32_t IOPENR;
  volatile uint32_t AHBENR;
  volatile uint32_t APBENR1;
  volatile uint32_t APBENR2;
  volatile uint32_t IOPSMENR;
  volatile uint32_t AHBSMENR;
  volatile uint32_t APBSMENR1;
  volatile uint32_t APBSMENR2;
  volatile uint32_t CCIPR;
  volatile uint32_t CCIPR2;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
} RCC_TypeDef;




typedef struct
{
  volatile uint32_t TR;
  volatile uint32_t DR;
  volatile uint32_t SSR;
  volatile uint32_t ICSR;
  volatile uint32_t PRER;
  volatile uint32_t WUTR;
  volatile uint32_t CR;
       uint32_t RESERVED0;
       uint32_t RESERVED1;
  volatile uint32_t WPR;
  volatile uint32_t CALR;
  volatile uint32_t SHIFTR;
  volatile uint32_t TSTR;
  volatile uint32_t TSDR;
  volatile uint32_t TSSSR;
       uint32_t RESERVED2;
  volatile uint32_t ALRMAR;
  volatile uint32_t ALRMASSR;
  volatile uint32_t ALRMBR;
  volatile uint32_t ALRMBSSR;
  volatile uint32_t SR;
  volatile uint32_t MISR;
       uint32_t RESERVED3;
  volatile uint32_t SCR;
  volatile uint32_t OR;
} RTC_TypeDef;




typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
       uint32_t RESERVED0;
  volatile uint32_t FLTCR;
       uint32_t RESERVED1[7];
  volatile uint32_t IER;
  volatile uint32_t SR;
  volatile uint32_t MISR;
       uint32_t RESERVED2;
  volatile uint32_t SCR;
       uint32_t RESERVED3[48];
  volatile uint32_t BKP0R;
  volatile uint32_t BKP1R;
  volatile uint32_t BKP2R;
  volatile uint32_t BKP3R;
  volatile uint32_t BKP4R;
} TAMP_TypeDef;




typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SR;
  volatile uint32_t DR;
  volatile uint32_t CRCPR;
  volatile uint32_t RXCRCR;
  volatile uint32_t TXCRCR;
  volatile uint32_t I2SCFGR;
  volatile uint32_t I2SPR;
} SPI_TypeDef;




typedef struct
{
  volatile uint32_t CFGR1;
       uint32_t RESERVED0[5];
  volatile uint32_t CFGR2;
       uint32_t RESERVED1[25];
  volatile uint32_t IT_LINE_SR[32];
} SYSCFG_TypeDef;




typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMCR;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t CCMR1;
  volatile uint32_t CCMR2;
  volatile uint32_t CCER;
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
  volatile uint32_t RCR;
  volatile uint32_t CCR1;
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
  volatile uint32_t BDTR;
  volatile uint32_t DCR;
  volatile uint32_t DMAR;
  volatile uint32_t OR1;
  volatile uint32_t CCMR3;
  volatile uint32_t CCR5;
  volatile uint32_t CCR6;
  volatile uint32_t AF1;
  volatile uint32_t AF2;
  volatile uint32_t TISEL;
} TIM_TypeDef;




typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t CR3;
  volatile uint32_t BRR;
  volatile uint32_t GTPR;
  volatile uint32_t RTOR;
  volatile uint32_t RQR;
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t RDR;
  volatile uint32_t TDR;
  volatile uint32_t PRESC;
} USART_TypeDef;





typedef struct
{
  volatile uint32_t CHEP0R;
  volatile uint32_t CHEP1R;
  volatile uint32_t CHEP2R;
  volatile uint32_t CHEP3R;
  volatile uint32_t CHEP4R;
  volatile uint32_t CHEP5R;
  volatile uint32_t CHEP6R;
  volatile uint32_t CHEP7R;
  volatile uint32_t RESERVED0[8];
  volatile uint32_t CNTR;
  volatile uint32_t ISTR;
  volatile uint32_t FNR;
  volatile uint32_t DADDR;
  volatile uint32_t RESERVED1;
  volatile uint32_t LPMCSR;
  volatile uint32_t BCDR;
} USB_DRD_TypeDef;




typedef struct
{
  volatile uint32_t TXBD;
  volatile uint32_t RXBD;
} USB_DRD_PMABuffDescTypeDef;







typedef struct
{
  volatile uint32_t CSR;
  volatile uint32_t CCR;
} VREFBUF_TypeDef;




typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_TypeDef;





typedef struct
{
  volatile uint32_t CFG1;
  volatile uint32_t CFG2;
  volatile uint32_t RESERVED0;
  volatile uint32_t CR;
  volatile uint32_t IMR;
  volatile uint32_t SR;
  volatile uint32_t ICR;
  volatile uint32_t TX_ORDSET;
  volatile uint32_t TX_PAYSZ;
  volatile uint32_t TXDR;
  volatile uint32_t RX_ORDSET;
  volatile uint32_t RX_PAYSZ;
  volatile uint32_t RXDR;
  volatile uint32_t RX_ORDEXT1;
  volatile uint32_t RX_ORDEXT2;

} UCPD_TypeDef;
# 17 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c" 2
# 1 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2/gpio.h" 1



# 1 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include\\stm32g0xx.h" 1
# 121 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include\\stm32g0xx.h"
# 1 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include/stm32g031xx.h" 1
# 68 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include/stm32g031xx.h"
typedef enum
{

  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  SVC_IRQn = -5,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,

  WWDG_IRQn = 0,
  PVD_IRQn = 1,
  RTC_TAMP_IRQn = 2,
  FLASH_IRQn = 3,
  RCC_IRQn = 4,
  EXTI0_1_IRQn = 5,
  EXTI2_3_IRQn = 6,
  EXTI4_15_IRQn = 7,
  DMA1_Channel1_IRQn = 9,
  DMA1_Channel2_3_IRQn = 10,
  DMA1_Ch4_5_DMAMUX1_OVR_IRQn = 11,
  ADC1_IRQn = 12,
  TIM1_BRK_UP_TRG_COM_IRQn = 13,
  TIM1_CC_IRQn = 14,
  TIM2_IRQn = 15,
  TIM3_IRQn = 16,
  LPTIM1_IRQn = 17,
  LPTIM2_IRQn = 18,
  TIM14_IRQn = 19,
  TIM16_IRQn = 21,
  TIM17_IRQn = 22,
  I2C1_IRQn = 23,
  I2C2_IRQn = 24,
  SPI1_IRQn = 25,
  SPI2_IRQn = 26,
  USART1_IRQn = 27,
  USART2_IRQn = 28,
  LPUART1_IRQn = 29,
} IRQn_Type;





# 1 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 1
# 29 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/CMSIS_5/CMSIS/Core/Include\\core_cm0plus.h" 3
# 112 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include/stm32g031xx.h" 2
# 122 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include/stm32g031xx.h"
typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IER;
  volatile uint32_t CR;
  volatile uint32_t CFGR1;
  volatile uint32_t CFGR2;
  volatile uint32_t SMPR;
       uint32_t RESERVED1;
       uint32_t RESERVED2;
  volatile uint32_t TR1;
  volatile uint32_t TR2;
  volatile uint32_t CHSELR;
  volatile uint32_t TR3;
       uint32_t RESERVED3[4];
  volatile uint32_t DR;
       uint32_t RESERVED4[23];
  volatile uint32_t AWD2CR;
  volatile uint32_t AWD3CR;
       uint32_t RESERVED5[3];
  volatile uint32_t CALFACT;
} ADC_TypeDef;

typedef struct
{
  volatile uint32_t CCR;
} ADC_Common_TypeDef;







typedef struct
{
  volatile uint32_t DR;
  volatile uint32_t IDR;
  volatile uint32_t CR;
       uint32_t RESERVED1;
  volatile uint32_t INIT;
  volatile uint32_t POL;
} CRC_TypeDef;





typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;
  volatile uint32_t APBFZ1;
  volatile uint32_t APBFZ2;
} DBG_TypeDef;




typedef struct
{
  volatile uint32_t CCR;
  volatile uint32_t CNDTR;
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
} DMA_TypeDef;




typedef struct
{
  volatile uint32_t CCR;
}DMAMUX_Channel_TypeDef;

typedef struct
{
  volatile uint32_t CSR;
  volatile uint32_t CFR;
}DMAMUX_ChannelStatus_TypeDef;

typedef struct
{
  volatile uint32_t RGCR;
}DMAMUX_RequestGen_TypeDef;

typedef struct
{
  volatile uint32_t RGSR;
  volatile uint32_t RGCFR;
}DMAMUX_RequestGenStatus_TypeDef;




typedef struct
{
  volatile uint32_t RTSR1;
  volatile uint32_t FTSR1;
  volatile uint32_t SWIER1;
  volatile uint32_t RPR1;
  volatile uint32_t FPR1;
       uint32_t RESERVED1[3];
       uint32_t RESERVED2[5];
       uint32_t RESERVED3[11];
  volatile uint32_t EXTICR[4];
       uint32_t RESERVED4[4];
  volatile uint32_t IMR1;
  volatile uint32_t EMR1;
} EXTI_TypeDef;




typedef struct
{
  volatile uint32_t ACR;
       uint32_t RESERVED1;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t ECCR;
       uint32_t RESERVED2;
  volatile uint32_t OPTR;
  volatile uint32_t PCROP1ASR;
  volatile uint32_t PCROP1AER;
  volatile uint32_t WRP1AR;
  volatile uint32_t WRP1BR;
  volatile uint32_t PCROP1BSR;
  volatile uint32_t PCROP1BER;
       uint32_t RESERVED8[17];
  volatile uint32_t SECR;
} FLASH_TypeDef;




typedef struct
{
  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFR[2];
  volatile uint32_t BRR;
} GPIO_TypeDef;





typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t OAR1;
  volatile uint32_t OAR2;
  volatile uint32_t TIMINGR;
  volatile uint32_t TIMEOUTR;
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t PECR;
  volatile uint32_t RXDR;
  volatile uint32_t TXDR;
} I2C_TypeDef;




typedef struct
{
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
  volatile uint32_t WINR;
} IWDG_TypeDef;




typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t IER;
  volatile uint32_t CFGR;
  volatile uint32_t CR;
  volatile uint32_t CMP;
  volatile uint32_t ARR;
  volatile uint32_t CNT;
  volatile uint32_t RESERVED1;
  volatile uint32_t CFGR2;
} LPTIM_TypeDef;





typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t CR3;
  volatile uint32_t CR4;
  volatile uint32_t SR1;
  volatile uint32_t SR2;
  volatile uint32_t SCR;
       uint32_t RESERVED1;
  volatile uint32_t PUCRA;
  volatile uint32_t PDCRA;
  volatile uint32_t PUCRB;
  volatile uint32_t PDCRB;
  volatile uint32_t PUCRC;
  volatile uint32_t PDCRC;
  volatile uint32_t PUCRD;
  volatile uint32_t PDCRD;
       uint32_t RESERVED2;
       uint32_t RESERVED3;
  volatile uint32_t PUCRF;
  volatile uint32_t PDCRF;
} PWR_TypeDef;




typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t ICSCR;
  volatile uint32_t CFGR;
  volatile uint32_t PLLCFGR;
  volatile uint32_t RESERVED0;
  volatile uint32_t RESERVED1;
  volatile uint32_t CIER;
  volatile uint32_t CIFR;
  volatile uint32_t CICR;
  volatile uint32_t IOPRSTR;
  volatile uint32_t AHBRSTR;
  volatile uint32_t APBRSTR1;
  volatile uint32_t APBRSTR2;
  volatile uint32_t IOPENR;
  volatile uint32_t AHBENR;
  volatile uint32_t APBENR1;
  volatile uint32_t APBENR2;
  volatile uint32_t IOPSMENR;
  volatile uint32_t AHBSMENR;
  volatile uint32_t APBSMENR1;
  volatile uint32_t APBSMENR2;
  volatile uint32_t CCIPR;
  volatile uint32_t RESERVED2;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
} RCC_TypeDef;




typedef struct
{
  volatile uint32_t TR;
  volatile uint32_t DR;
  volatile uint32_t SSR;
  volatile uint32_t ICSR;
  volatile uint32_t PRER;
  volatile uint32_t WUTR;
  volatile uint32_t CR;
       uint32_t RESERVED0;
       uint32_t RESERVED1;
  volatile uint32_t WPR;
  volatile uint32_t CALR;
  volatile uint32_t SHIFTR;
  volatile uint32_t TSTR;
  volatile uint32_t TSDR;
  volatile uint32_t TSSSR;
       uint32_t RESERVED2;
  volatile uint32_t ALRMAR;
  volatile uint32_t ALRMASSR;
  volatile uint32_t ALRMBR;
  volatile uint32_t ALRMBSSR;
  volatile uint32_t SR;
  volatile uint32_t MISR;
       uint32_t RESERVED3;
  volatile uint32_t SCR;
  volatile uint32_t OR;
} RTC_TypeDef;




typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
       uint32_t RESERVED0;
  volatile uint32_t FLTCR;
       uint32_t RESERVED1[7];
  volatile uint32_t IER;
  volatile uint32_t SR;
  volatile uint32_t MISR;
       uint32_t RESERVED2;
  volatile uint32_t SCR;
       uint32_t RESERVED3[48];
  volatile uint32_t BKP0R;
  volatile uint32_t BKP1R;
  volatile uint32_t BKP2R;
  volatile uint32_t BKP3R;
  volatile uint32_t BKP4R;
} TAMP_TypeDef;




typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SR;
  volatile uint32_t DR;
  volatile uint32_t CRCPR;
  volatile uint32_t RXCRCR;
  volatile uint32_t TXCRCR;
  volatile uint32_t I2SCFGR;
  volatile uint32_t I2SPR;
} SPI_TypeDef;




typedef struct
{
  volatile uint32_t CFGR1;
       uint32_t RESERVED0[5];
  volatile uint32_t CFGR2;
       uint32_t RESERVED1[25];
  volatile uint32_t IT_LINE_SR[32];
} SYSCFG_TypeDef;




typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMCR;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t CCMR1;
  volatile uint32_t CCMR2;
  volatile uint32_t CCER;
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
  volatile uint32_t RCR;
  volatile uint32_t CCR1;
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
  volatile uint32_t BDTR;
  volatile uint32_t DCR;
  volatile uint32_t DMAR;
  volatile uint32_t OR1;
  volatile uint32_t CCMR3;
  volatile uint32_t CCR5;
  volatile uint32_t CCR6;
  volatile uint32_t AF1;
  volatile uint32_t AF2;
  volatile uint32_t TISEL;
} TIM_TypeDef;




typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t CR3;
  volatile uint32_t BRR;
  volatile uint32_t GTPR;
  volatile uint32_t RTOR;
  volatile uint32_t RQR;
  volatile uint32_t ISR;
  volatile uint32_t ICR;
  volatile uint32_t RDR;
  volatile uint32_t TDR;
  volatile uint32_t PRESC;
} USART_TypeDef;




typedef struct
{
  volatile uint32_t CSR;
  volatile uint32_t CCR;
} VREFBUF_TypeDef;




typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_TypeDef;
# 122 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include\\stm32g0xx.h" 2
# 143 "C:/Users/bjpro/OneDrive/Documents/GitHub/HMM/HMMM/Exam2/STM32G0xx/Device/Include\\stm32g0xx.h"
typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;


typedef enum
{
  SUCCESS = 0,
  ERROR = !SUCCESS
} ErrorStatus;
# 5 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2/gpio.h" 2



void GPIO_InitOutput(GPIO_TypeDef *port, uint8_t pin);
void GPIO_InitInput(GPIO_TypeDef *port, uint8_t pin);
void GPIO_InitAlternateF(GPIO_TypeDef *port, uint8_t pin, uint8_t af);


void GPIO_Set(GPIO_TypeDef *port, uint8_t pin);
void GPIO_Clear(GPIO_TypeDef *port, uint8_t pin);
void GPIO_Toggle(GPIO_TypeDef *port, uint8_t pin);
uint8_t GPIO_Read(GPIO_TypeDef *port, uint8_t pin);
# 18 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c" 2
# 1 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2/uart.h" 1
# 17 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2/uart.h"
void UART_Init(USART_TypeDef*, uint32_t, char);




void UART_TxByte(USART_TypeDef*, uint8_t);



void UART_TxStr(USART_TypeDef*, const char*);





void UART_TxBuffer(USART_TypeDef*, uint8_t*, uint16_t);




uint8_t UART_RxByte(USART_TypeDef* , uint8_t*);

void TERM_ClearScreen (USART_TypeDef * pUSART);
void TERM_GotoXY (USART_TypeDef * pUSART, int iCol, int iRow);
void TERM_TxStringXY (USART_TypeDef * pUSART, int iCol, int iRow, char * pStr);
# 19 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c" 2
# 1 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2/clock.h" 1
# 14 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2/clock.h"
void Clock_InitPll(uint32_t pll_config);
void Clock_SelectPLL(void);
void Clock_EnableOutput(uint32_t source, uint32_t div);
# 20 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c" 2
# 1 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2/timer.h" 1
# 14 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2/timer.h"
typedef enum CCR_Typedef__
{
    TimCCR1 = 0x00,
    TimCCR2 = 0x04,
    TimCCR3 = 0x08,
    TimCCR4 = 0x0C,
    TimCCR5 = 0x24,
    TimCCR6 = 0x28,
}CCR_Typedef;

typedef enum ChannelMode_Typedef__
{
    OutputCompareToggle,
    InputCapture,
    Pwm1,
    Pwm2,
}ChannelMode_Typedef;


typedef enum Timer_IE_Typedef__
{

    TimUIE = 0x01 << 0,
    TimCC1IE = 0x01 << 1,
    TimCC2IE = 0x01 << 2,
    TimCC3IE = 0x01 << 3,
    TimCC4IE = 0x01 << 4,
}Timer_IE;






void Timer_Init(TIM_TypeDef * timer, uint16_t psc, uint16_t period);





void Timer_SetupChannel(TIM_TypeDef * timer, CCR_Typedef ccr, ChannelMode_Typedef chMode);





void Timer_WriteCCR(TIM_TypeDef * timer, CCR_Typedef ccr, uint32_t ccrTicks);





void Timer_EnableInterrupt(TIM_TypeDef * timer, IRQn_Type timerIRQn, Timer_IE interruptMask);




void Timer_SetEnable(TIM_TypeDef * timer, uint16_t en);

void Timer_SetmsTick(TIM_TypeDef * pTimer);
void Timer_SetusTick(TIM_TypeDef * pTimer);
void Timer_DelayTicks(TIM_TypeDef * pTimer, uint16_t ticks);
uint8_t Timer_PollUIF(TIM_TypeDef * pTimer);
# 21 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c" 2
# 30 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c"
static void UpdateDisplay(uint32_t leftCount, uint32_t rightCount)
{
    char buf[20];

    TERM_TxStringXY(((USART_TypeDef *) (((0x40000000UL)) + 0x00004400UL)), 1, 10, "LEFT SW:");
    TERM_TxStringXY(((USART_TypeDef *) (((0x40000000UL)) + 0x00004400UL)), 1, 11, "RIGHT SW:");

    sprintf(buf, "%02lu", (unsigned long)leftCount);
    TERM_TxStringXY(((USART_TypeDef *) (((0x40000000UL)) + 0x00004400UL)), 15, 10, buf);

    sprintf(buf, "%02lu", (unsigned long)rightCount);
    TERM_TxStringXY(((USART_TypeDef *) (((0x40000000UL)) + 0x00004400UL)), 15, 11, buf);
}
# 52 "C:\\Users\\bjpro\\OneDrive\\Documents\\GitHub\\HMM\\HMMM\\Exam2\\main.c"
int main(void)
{

    uint32_t leftCount = 0;
    uint32_t rightCount = 0;
    int leftArmed = 1;
    int rightArmed = 1;


    int buttonReady = 1;


    Clock_InitPll(PLL_50MHZ);


    ((RCC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x00001000UL))->IOPENR |= (0x1UL << (0U));
    ((RCC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x00001000UL))->IOPENR |= (0x1UL << (2U));


    ((RCC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x00001000UL))->APBENR1 |= (0x1UL << (17U));
    ((RCC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x00001000UL))->APBENR1 |= (0x1UL << (4U));
    ((RCC_TypeDef *) (((0x40000000UL) + 0x00020000UL) + 0x00001000UL))->APBENR1 |= (0x1UL << (5U));


    GPIO_InitAlternateF(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000000UL)), 9, 0);
    Clock_EnableOutput((1U << 24), MCO_Div4);


    GPIO_InitAlternateF(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000000UL)), 2, 1);
    GPIO_InitAlternateF(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000000UL)), 3, 1);


    GPIO_InitOutput(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000000UL)), 5);


    GPIO_InitOutput(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000000UL)), 6);





    GPIO_InitInput(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000800UL)), 4);
    GPIO_SetPullMode(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000800UL)), 4, PullMode_PullDown);
    GPIO_InitInput(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000800UL)), 5);
    GPIO_SetPullMode(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000800UL)), 5, PullMode_PullDown);


    GPIO_InitInput(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000800UL)), 13);
    GPIO_SetPullMode(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000800UL)), 13, PullMode_PullUp);


    UART_Init(((USART_TypeDef *) (((0x40000000UL)) + 0x00004400UL)), 115200, 0);
    TERM_ClearScreen(((USART_TypeDef *) (((0x40000000UL)) + 0x00004400UL)));
    UpdateDisplay(leftCount, rightCount);


    Timer_SetusTick(((TIM_TypeDef *) (((0x40000000UL)) + 0x00001000UL)));
    ((TIM_TypeDef *) (((0x40000000UL)) + 0x00001000UL))->ARR = 7700 - 1;
    Timer_SetEnable(((TIM_TypeDef *) (((0x40000000UL)) + 0x00001000UL)), 1);


    Timer_SetmsTick(((TIM_TypeDef *) (((0x40000000UL)) + 0x00001400UL)));

    while (1)
    {

        if (Timer_PollUIF(((TIM_TypeDef *) (((0x40000000UL)) + 0x00001000UL))))
            GPIO_Toggle(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000000UL)), 6);


        int leftPressed = GPIO_Read(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000800UL)), 4);
        int rightPressed = GPIO_Read(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000800UL)), 5);

        if (leftPressed && leftArmed)
        {
            leftCount++;
            leftArmed = 0;
            UpdateDisplay(leftCount, rightCount);
        }
        else if (!leftPressed)
        {
            leftArmed = 1;
        }

        if (rightPressed && rightArmed)
        {
            rightCount++;
            rightArmed = 0;
            UpdateDisplay(leftCount, rightCount);
        }
        else if (!rightPressed)
        {
            rightArmed = 1;
        }


        int pressed = (GPIO_Read(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000800UL)), 13) == 0);

        if (pressed && buttonReady)
        {
            buttonReady = 0;
            GPIO_Set(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000000UL)), 5);
            Timer_DelayTicks(((TIM_TypeDef *) (((0x40000000UL)) + 0x00001400UL)), 75);
            GPIO_Clear(((GPIO_TypeDef *) ((0x50000000UL) + 0x00000000UL)), 5);
        }
        else if (!pressed)
        {
            buttonReady = 1;
        }
    }
}
