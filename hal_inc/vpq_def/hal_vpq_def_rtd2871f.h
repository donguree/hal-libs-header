#ifndef	_HAL_VPQ_DEF_RTD2871F_H_
#define	_HAL_VPQ_DEF_RTD2871F_H_

/**********************************************************************
	CM
***********************************************************************/
#define	CHIP_CM_TBLPOINT	8

typedef enum{
	CHIP_CM_COLOR_REGION_RED,
	CHIP_CM_COLOR_REGION_GRN,
	CHIP_CM_COLOR_REGION_BLU,
	CHIP_CM_COLOR_REGION_CYN,
	CHIP_CM_COLOR_REGION_MGT,
	CHIP_CM_COLOR_REGION_YLW,
	CHIP_CM_COLOR_REGION_SKIN,
	CHIP_CM_COLOR_REGION_RESERVED1,
	CHIP_CM_COLOR_REGION_RESERVED2,
	CHIP_CM_COLOR_REGION_MAX
}CHIP_CM_COLOR_REGION_T;

typedef struct{
	bool		enable;
	CHIP_CM_COLOR_REGION_T	regionNum;
	UINT16		hue_x[CHIP_CM_TBLPOINT];
	UINT16		hue_g[CHIP_CM_TBLPOINT];
	UINT16		sat_x[CHIP_CM_TBLPOINT];
	UINT16		sat_g[CHIP_CM_TBLPOINT];
	UINT16		Int_x[CHIP_CM_TBLPOINT];
	UINT16		Int_g[CHIP_CM_TBLPOINT];
}CHIP_COLOR_REGION_T;

typedef struct{
	CHIP_COLOR_REGION_T		stColorRegion[CHIP_CM_COLOR_REGION_MAX];
	BOOLEAN keepY;
}CHIP_COLOR_REGION_TYPE_T;

typedef struct {
	CHIP_COLOR_REGION_TYPE_T	stColorRegionType;
} CHIP_CM_INIT_ADV_COLOR_T;

typedef CHIP_CM_INIT_ADV_COLOR_T CHIP_CM_INIT_EXP_COLOR_T;

typedef struct {
	UINT8	stColorGainHue;
	UINT8	stColorGainSat;
	UINT8	stColorGainInt;
} CHIP_COLOR_LEVEL_GAIN_T;

typedef struct {
	UINT16	masterGain;
	CHIP_COLOR_LEVEL_GAIN_T	stColorGain;
} CHIP_COLOR_GAIN_T;

typedef struct {
	CHIP_COLOR_GAIN_T		stColor[CHIP_CM_COLOR_REGION_MAX];
} CHIP_CM_DYNAMIC_COLOR_T;

typedef struct {
	CHIP_COLOR_GAIN_T		stColor[CHIP_CM_COLOR_REGION_MAX];
} CHIP_CM_DATA_T;

typedef struct{
	UINT8		UVoffsetByY_mode_en;
	UINT8		UVoffsetByY_mode;

	UINT8		Uoffset_m0;
	UINT8		Uoffset_m1;
	UINT8		Uoffset_m2;
	UINT8		Uoffset_m3;
	UINT8		Uoffset_m4;
	UINT8		Uoffset_m5;
	UINT8		Uoffset_m6;
	UINT8		Uoffset_m7;
	UINT8		Uoffset_m8;
	UINT8		Uoffset_m9;
	UINT8		Uoffset_m10;
	UINT8		Uoffset_m11;
	UINT8		Uoffset_m12;
	UINT8		Uoffset_m13;
	UINT8		Uoffset_m14;
	UINT8		Uoffset_m15;
	UINT8		Uoffset_m16;

	UINT8		Voffset_m0;
	UINT8		Voffset_m1;
	UINT8		Voffset_m2;
	UINT8		Voffset_m3;
	UINT8		Voffset_m4;
	UINT8		Voffset_m5;
	UINT8		Voffset_m6;
	UINT8		Voffset_m7;
	UINT8		Voffset_m8;
	UINT8		Voffset_m9;
	UINT8		Voffset_m10;
	UINT8		Voffset_m11;
	UINT8		Voffset_m12;
	UINT8		Voffset_m13;
	UINT8		Voffset_m14;
	UINT8		Voffset_m15;
	UINT8		Voffset_m16;

	UINT8		Ustep_m0;
	UINT8		Ustep_m1;
	UINT8		Ustep_m2;
	UINT8		Ustep_m3;
	UINT8		Ustep_m4;
	UINT8		Ustep_m5;
	UINT8		Ustep_m6;
	UINT8		Ustep_m7;
	UINT8		Ustep_m8;
	UINT8		Ustep_m9;
	UINT8		Ustep_m10;
	UINT8		Ustep_m11;
	UINT8		Ustep_m12;
	UINT8		Ustep_m13;
	UINT8		Ustep_m14;
	UINT8		Ustep_m15;
	UINT8		Ustep_m16;

	UINT8		Vstep_m0;
	UINT8		Vstep_m1;
	UINT8		Vstep_m2;
	UINT8		Vstep_m3;
	UINT8		Vstep_m4;
	UINT8		Vstep_m5;
	UINT8		Vstep_m6;
	UINT8		Vstep_m7;
	UINT8		Vstep_m8;
	UINT8		Vstep_m9;
	UINT8		Vstep_m10;
	UINT8		Vstep_m11;
	UINT8		Vstep_m12;
	UINT8		Vstep_m13;
	UINT8		Vstep_m14;
	UINT8		Vstep_m15;
	UINT8		Vstep_m16;

	UINT8		Index_0;
	UINT8		Index_1;
	UINT8		Index_2;
	UINT8		Index_3;
	UINT8		Index_4;
	UINT8		Index_5;
	UINT8		Index_6;
	UINT8		Index_7;
	UINT8		Index_8;
	UINT8		Index_9;
	UINT8		Index_10;
	UINT8		Index_11;
	UINT8		Index_12;
	UINT8		Index_13;
	UINT8		Index_14;
	UINT8		Index_15;
	UINT8		Index_16;

	UINT8		GAMMA_M_BS_EN;

	UINT8		GAMMA_BS_SAT_THD;
	UINT8		GAMMA_BS_R_GAIN;
	UINT8		GAMMA_BS_G_GAIN;
	UINT8		GAMMA_BS_B_GAIN;

	UINT8		GAMMA_BS_Y0;
	UINT8		GAMMA_BS_Y1;
	UINT8		GAMMA_BS_Y2;
	UINT8		GAMMA_BS_Y3;
	UINT8		GAMMA_BS_Y4;
	UINT8		GAMMA_BS_Y5;
	UINT8		GAMMA_BS_Y6;
	UINT8		GAMMA_BS_Y7;

	UINT16		GAMMA_BS_R_OFST_0;
	UINT16		GAMMA_BS_R_OFST_1;
	UINT16		GAMMA_BS_R_OFST_2;
	UINT16		GAMMA_BS_R_OFST_3;
	UINT16		GAMMA_BS_R_OFST_4;
	UINT16		GAMMA_BS_R_OFST_5;
	UINT16		GAMMA_BS_R_OFST_6;
	UINT16		GAMMA_BS_R_OFST_7;

	UINT16		GAMMA_BS_G_OFST_0;
	UINT16		GAMMA_BS_G_OFST_1;
	UINT16		GAMMA_BS_G_OFST_2;
	UINT16		GAMMA_BS_G_OFST_3;
	UINT16		GAMMA_BS_G_OFST_4;
	UINT16		GAMMA_BS_G_OFST_5;
	UINT16		GAMMA_BS_G_OFST_6;
	UINT16		GAMMA_BS_G_OFST_7;

	UINT16		GAMMA_BS_B_OFST_0;
	UINT16		GAMMA_BS_B_OFST_1;
	UINT16		GAMMA_BS_B_OFST_2;
	UINT16		GAMMA_BS_B_OFST_3;
	UINT16		GAMMA_BS_B_OFST_4;
	UINT16		GAMMA_BS_B_OFST_5;
	UINT16		GAMMA_BS_B_OFST_6;
	UINT16		GAMMA_BS_B_OFST_7;

	UINT8		GAMMA_BS_R_STEP_0;
	UINT8		GAMMA_BS_R_STEP_1;
	UINT8		GAMMA_BS_R_STEP_2;
	UINT8		GAMMA_BS_R_STEP_3;
	UINT8		GAMMA_BS_R_STEP_4;
	UINT8		GAMMA_BS_R_STEP_5;
	UINT8		GAMMA_BS_R_STEP_6;
	UINT8		GAMMA_BS_R_STEP_7;

	UINT8		GAMMA_BS_G_STEP_0;
	UINT8		GAMMA_BS_G_STEP_1;
	UINT8		GAMMA_BS_G_STEP_2;
	UINT8		GAMMA_BS_G_STEP_3;
	UINT8		GAMMA_BS_G_STEP_4;
	UINT8		GAMMA_BS_G_STEP_5;
	UINT8		GAMMA_BS_G_STEP_6;
	UINT8		GAMMA_BS_G_STEP_7;

	UINT8		GAMMA_BS_B_STEP_0;
	UINT8		GAMMA_BS_B_STEP_1;
	UINT8		GAMMA_BS_B_STEP_2;
	UINT8		GAMMA_BS_B_STEP_3;
	UINT8		GAMMA_BS_B_STEP_4;
	UINT8		GAMMA_BS_B_STEP_5;
	UINT8		GAMMA_BS_B_STEP_6;
	UINT8		GAMMA_BS_B_STEP_7;
}CHIP_COLOR_WHITE_T;

/**********************************************************************
	DC
***********************************************************************/
typedef struct {
	BOOLEAN	chroma_gain_en;
	BOOLEAN	chroma_gain_mode;
	BOOLEAN	chroma_gain_lookup_mode;
	UINT8	chroma_gain_base;
	BOOLEAN	chroma_enhance_above_tab_select_main;
	BOOLEAN	chroma_enhance_below_tab_select_main;
	BOOLEAN	saturation_byy_u_tab_select_main;
	BOOLEAN	saturation_byy_v_tab_select_main;

	BOOLEAN	chroma_gain_limit_en;
	UINT8	chroma_gain_limit_seg[8];
	SINT8	chroma_gain_tab0_seg[17];
	SINT8	chroma_gain_tab1_seg[17];
} CHIP_DCC_CHROMA_GAIN_T;

typedef struct {
	UINT16	y0_center;
	UINT16	u0_center;
	UINT16	v0_center;
	UINT8	y0_range;
	UINT8	u0_range;
	UINT8	v0_range;

	UINT16	y1_center;
	UINT16	u1_center;
	UINT16	v1_center;
	UINT8	y1_range;
	UINT8	u1_range;
	UINT8	v1_range;

	UINT16	y2_center;
	UINT16	u2_center;
	UINT16	v2_center;
	UINT8	y2_range;
	UINT8	u2_range;
	UINT8	v2_range;

	UINT16	y3_center;
	UINT16	u3_center;
	UINT16	v3_center;
	UINT8	y3_range;
	UINT8	u3_range;
	UINT8	v3_range;
} CHIP_DCC_SKIN_TONE_RANGE_T;

typedef struct {
	UINT16	D_DCC_SKIN_EN;

	UINT8	Y0_seg[8];
	UINT8	Y1_seg[8];
	UINT8	Y2_seg[8];
	UINT8	Y3_seg[8];
	UINT8	C0_seg[8];
	UINT8	C1_seg[8];
	UINT8	C2_seg[8];
	UINT8	C3_seg[8];
} CHIP_DCC_SKIN_TONE_GAIN_T;


typedef struct {
	CHIP_DCC_SKIN_TONE_RANGE_T	range;
	CHIP_DCC_SKIN_TONE_GAIN_T	value;
} CHIP_DCC_SKINTONE_T;

typedef struct {
	CHIP_DCC_CHROMA_GAIN_T	stChromaGain;
	CHIP_DCC_SKINTONE_T	stSkinTone;
} CHIP_DC2P_DYNAMIC_CONTRAST_T;

/**********************************************************************
	NR
***********************************************************************/
typedef struct{
	BOOLEAN	spatialEnableY;
	UINT8	Gain;
	UINT16	thrUpBnd;
	UINT8	thrLowBnd;
	UINT8	thrStep;
	UINT8	rzFilterSize;
	UINT8	weight2Y;
	UINT8	weight3Y;
	UINT8	weight4Y;
	UINT8	spatialThlY;
	UINT8	spatialThl2Y;
	UINT8	spatialThl4Y;
}CHIP_LPFY_UI_T;

typedef struct{
	BOOLEAN	spatialEnableC;
	UINT8	lpResultWeightC;
	UINT8	rzFilterSize;
	UINT8	weight2C;
	UINT8	weight3C;
	UINT8	weight4C;
	UINT8	spatialThlC;
	UINT8	spatialThl2C;
	UINT8	spatialThl4C;
}CHIP_LPFC_UI_T;

typedef struct{
	UINT16	curve_step1;
	UINT16	curve_step2;
	UINT16	curve_step3;
	UINT16	curve_step4;
	UINT16	curve_step5;
	UINT16	curve_step6;
	UINT16	curve_step7;
	UINT16	curve_step8;
}CHIP_NR_CURVEMAPPING_STEP_T;

typedef struct{
	UINT8	weight1_0;
	UINT8	weight1_1;
	UINT8	weight1_2;
	UINT8	weight1_3;
	UINT8	weight1_4;
	UINT8	weight1_5;
	UINT8	weight1_6;
	UINT8	weight1_7;
	UINT8	weight1_8;
	UINT8	weight2_0;
	UINT8	weight2_1;
	UINT8	weight2_2;
	UINT8	weight2_3;
	UINT8	weight2_4;
	UINT8	weight2_5;
	UINT8	weight2_6;
	UINT8	weight2_7;
	UINT8	weight2_8;
}CHIP_NR_CURVEMAPPING_WEIGHT_UI_T;

typedef struct{
	UINT8	weight1Y;
	UINT8	weight2Y;
	UINT8	deringWeight;
	UINT8	ringRange;
	UINT8	ringgain;
}CHIP_BLENDING_T;

typedef struct{
// RTNR Old Mode_General Ctrl
	BOOLEAN	y_enable;
	UINT8	mad[15][10];
}CHIP_TNRY_T;

typedef struct{
	BOOLEAN	C_enable;
	UINT8	mad[7][10];
}CHIP_TNRC_T;



typedef struct{
	CHIP_LPFY_UI_T	stLPF_Y;
	CHIP_LPFC_UI_T	stLPF_C;
	CHIP_NR_CURVEMAPPING_STEP_T	stCurveMappingStep;
	CHIP_NR_CURVEMAPPING_WEIGHT_UI_T stCurveMappingWeight;
	CHIP_BLENDING_T	stBlending;
	CHIP_TNRY_T	stTNRY;
	CHIP_TNRC_T	stTNRC;
}CHIP_NOISE_REDUCTION_T;

typedef struct{
	BOOLEAN	edgeLPFenable;
	UINT8	edgeTheshold;
	UINT8	edgeThesholdStep;
	BOOLEAN	farVarfarEdgeRefineEnable;
	UINT8		Range;
	UINT8	farVarGain;
	UINT8	farVaroffset;
	UINT8	HdiffFracShift;
	UINT8	varDiffRefinegain;
	UINT8	VdiffFracShift;
	BOOLEAN	decayEnable;
	UINT8	HdecayStart;
	UINT8	HdecayStep;
	UINT8	VdecayStart;
	UINT8	VdecayStep;
	UINT8	mnrWeight;
	UINT8	blendingMode;
}CHIP_MNR_T;

typedef struct{
	BOOLEAN	mnrEnable;
	UINT8	posNLevelOffset;
	UINT8	posNLevelShift;
	UINT8	negNLevelOffset;
	UINT8	negNLevelShift;
	UINT8	edgeStrengthGain;
	UINT8	threshold;
	UINT8	thresholdStep;
	UINT8	shift;
}CHIP_MNR_UI_T;

typedef struct{
	UINT8	MpegResultWeight_H;
	UINT8	dcModeFilter;
	UINT8	mpgDCGain;
}CHIP_MPEGNR_UI_T;

typedef struct{
	CHIP_MNR_T			stMNR;
	CHIP_MNR_UI_T		stMNR_UI;
	CHIP_MPEGNR_UI_T	stMPEGNR_UI;
}CHIP_MPEG_NOISE_REDUCTION_T;

/**********************************************************************
	PC
***********************************************************************/
typedef struct{
	SINT32	sContrast;
	SINT32	sBrightness;
	SINT32	sSaturation;
	SINT32	sHue;
	SINT32	sDimming;
}CHIP_PC_T;


/**********************************************************************
	SHP
***********************************************************************/

typedef struct{
	UINT8	edge_mode;
	UINT8	sobel_mode;
	UINT8	edgextrange;
	UINT8	sobel_upbnd;
	UINT8	sobel_stepbit;
	UINT8	zdiff_upbnd;
	UINT8	zdiff_stepbit;
	UINT8	zigsftbit_reg;
	UINT8	texture_enable;
	UINT8	tex_upbnd;
	UINT8	tex_stepbit;
	UINT8	actsftbit_reg;
	UINT8	lpf_mode;
	UINT8	lpf_filter;
}CHIP_SEGMENTATION_T;

typedef struct{
	BOOLEAN	edgeCoringEn;
	BOOLEAN	edgeGainEn;
	UINT8	bigEdgeRatio;
	UINT8	smallEdgeRatio;
	UINT8	deltaEdgeRatio;
	UINT8	smallEdgeUlevel;
	UINT8	deltaEdgeUlevel;
	UINT8	edgeCoringClip;
	UINT8	edgeGainBound;
	UINT8	edgeSerRange;
	UINT8	Edge_delta_ext_R;
}CHIP_EDGE_CORING_MODE_T;

typedef struct{
	UINT8	linearY_Umode;
	UINT8	linearY_Lmode;
	UINT8	linearY_UB;
	UINT8	linearY_LB;
}CHIP_Y_REMAPPING_T;

typedef struct{
	BOOLEAN	edgpk_en;
	UINT8	edge_select_filter;
	UINT8	edge_lpf_shift;
	SINT16	coef_c0_0;
	SINT8	coef_c1_0;
	SINT8	coef_c2_0;
	SINT8	coef_c3_0;
	SINT8	coef_c4_0;
	SINT8	coef_c5_0;
	SINT8	coef_c6_0;
	SINT8	coef_c7_0;
	SINT8	coef_c8_0;
	SINT8	coef_c9_0;
	SINT8	coef_c10_0;
	SINT8	coef_c0_1;
	SINT8	coef_c1_1;
	SINT8	coef_c2_1;
	SINT8	coef_c3_1;
	SINT8	coef_c4_1;
	SINT8	coef_c5_1;
	SINT8	coef_c0_2;
	SINT8	coef_c1_2;
	SINT8	coef_c2_2;
	SINT8	coef_c3_2;
	SINT8	coef_c4_2;
	SINT8	coef_c5_2;
	SINT8	coef_c0_3;
	SINT8	coef_c0_4;
}CHIP_EDGE_HPF_T;

typedef struct{
	UINT16	pos_s1;
	UINT16	pos_s2;
	UINT16	pos_s3;
	UINT16	pos_s4;
	UINT16	pos_s5;
	UINT16	pos_s6;
	UINT16	pos_s7;
	UINT16	pos_s8;
	UINT16	pos_s9;
	UINT16	pos_s10;
	UINT16	pos_s11;
	UINT16	pos_s12;
	UINT16	pos_s13;
	UINT16	pos_s14;
	UINT16	neg_s1;
	UINT16	neg_s2;
	UINT16	neg_s3;
	UINT16	neg_s4;
	UINT16	neg_s5;
	UINT16	neg_s6;
	UINT16	neg_s7;
	UINT16	neg_s8;
	UINT16	neg_s9;
	UINT16	neg_s10;
	UINT16	neg_s11;
	UINT16	neg_s12;
	UINT16	neg_s13;
	UINT16	neg_s14;
}CHIP_EDGE_CURVEMAPPING_STEP_T;

typedef struct{
	UINT8	Gain_Pos;
	UINT8	Gain_Neg;
	UINT8	Gain_Pos2;
	UINT8	Gain_Neg2;
	UINT16	Range_Pos;
	UINT16	Range_Neg;
	UINT8	Coring;
	UINT8	Edge_Shift;
	BOOLEAN	Edge_curve_en;
	UINT16	pos_g0;
	UINT16	pos_g1;
	UINT16	pos_g2;
	UINT16	pos_g3;
	UINT16	pos_g4;
	UINT16	pos_g5;
	UINT16	pos_g6;
	UINT16	pos_g7;
	UINT16	pos_g8;
	UINT16	pos_g9;
	UINT16	pos_g10;
	UINT16	pos_g11;
	UINT16	pos_g12;
	UINT16	pos_g13;
	UINT16	pos_g14;
	UINT16	neg_g0;
	UINT16	neg_g1;
	UINT16	neg_g2;
	UINT16	neg_g3;
	UINT16	neg_g4;
	UINT16	neg_g5;
	UINT16	neg_g6;
	UINT16	neg_g7;
	UINT16	neg_g8;
	UINT16	neg_g9;
	UINT16	neg_g10;
	UINT16	neg_g11;
	UINT16	neg_g12;
	UINT16	neg_g13;
	UINT16	neg_g14;
}CHIP_EDGE_CURVEMAPPING_UI_T;

typedef struct{
	BOOLEAN	texpk_en;
	UINT8	text_select_filter;
	UINT8	tex_lpf_shift;
	SINT16	coef_c0_0;
	SINT8	coef_c1_0;
	SINT8	coef_c2_0;
	SINT8	coef_c3_0;
	SINT8	coef_c4_0;
	SINT8	coef_c5_0;
	SINT8	coef_c6_0;
	SINT8	coef_c7_0;
	SINT8	coef_c8_0;
	SINT8	coef_c9_0;
	SINT8	coef_c10_0;
	SINT8	coef_c0_1;
	SINT8	coef_c1_1;
	SINT8	coef_c2_1;
	SINT8	coef_c3_1;
	SINT8	coef_c4_1;
	SINT8	coef_c5_1;
	SINT8	coef_c0_2;
	SINT8	coef_c1_2;
	SINT8	coef_c2_2;
	SINT8	coef_c3_2;
	SINT8	coef_c4_2;
	SINT8	coef_c5_2;
	SINT8	coef_c0_3;
	SINT8	coef_c0_4;
}CHIP_TEXTURE_HPF_T;

typedef struct{
	UINT16	pos_s1;
	UINT16	pos_s2;
	UINT16	pos_s3;
	UINT16	pos_s4;
	UINT16	pos_s5;
	UINT16	pos_s6;
	UINT16	pos_s7;
	UINT16	pos_s8;
	UINT16	pos_s9;
	UINT16	pos_s10;
	UINT16	pos_s11;
	UINT16	pos_s12;
	UINT16	pos_s13;
	UINT16	pos_s14;
	UINT16	neg_s1;
	UINT16	neg_s2;
	UINT16	neg_s3;
	UINT16	neg_s4;
	UINT16	neg_s5;
	UINT16	neg_s6;
	UINT16	neg_s7;
	UINT16	neg_s8;
	UINT16	neg_s9;
	UINT16	neg_s10;
	UINT16	neg_s11;
	UINT16	neg_s12;
	UINT16	neg_s13;
	UINT16	neg_s14;
}CHIP_TEXTURE_CURVEMAPPING_STEP_T;

typedef struct{
	UINT8	Gain_Pos;
	UINT8	Gain_Neg;
	UINT8	Gain_Pos2;
	UINT8	Gain_Neg2;
	UINT16	Range_Pos;
	UINT16	Range_Neg;
	UINT8	Coring;
	UINT8	Tex_Shift;
	BOOLEAN	enable;
	UINT16	pos_g0;
	UINT16	pos_g1;
	UINT16	pos_g2;
	UINT16	pos_g3;
	UINT16	pos_g4;
	UINT16	pos_g5;
	UINT16	pos_g6;
	UINT16	pos_g7;
	UINT16	pos_g8;
	UINT16	pos_g9;
	UINT16	pos_g10;
	UINT16	pos_g11;
	UINT16	pos_g12;
	UINT16	pos_g13;
	UINT16	pos_g14;
	UINT16	neg_g0;
	UINT16	neg_g1;
	UINT16	neg_g2;
	UINT16	neg_g3;
	UINT16	neg_g4;
	UINT16	neg_g5;
	UINT16	neg_g6;
	UINT16	neg_g7;
	UINT16	neg_g8;
	UINT16	neg_g9;
	UINT16	neg_g10;
	UINT16	neg_g11;
	UINT16	neg_g12;
	UINT16	neg_g13;
	UINT16	neg_g14;
}CHIP_TEXTURE_CURVEMAPPING_UI_T;

typedef struct{
	SINT16	h9_c0;
	SINT8	h9_c1;
	SINT8	h9_c2;
	SINT8	h9_c3;
	SINT8	h9_c4;
	SINT16	h13_c0;
	SINT8	h13_c1;
	SINT8	h13_c2;
	SINT8	h13_c3;
	SINT8	h13_c4;
	SINT8	h13_c5;
	SINT8	h13_c6;
	SINT16	h21_c0;
	SINT8	h21_c1;
	SINT8	h21_c2;
	SINT8	h21_c3;
	SINT8	h21_c4;
	SINT8	h21_c5;
	SINT8	h21_c6;
	SINT8	h21_c7;
	SINT8	h21_c8;
	SINT8	h21_c9;
	SINT8	h21_c10;
	SINT16	v91_c0;
	SINT8	v91_c1;
	SINT8	v91_c2;
	SINT8	v91_c3;
	SINT8	v91_c4;
	SINT16	v92_c0;
	SINT8	v92_c1;
	SINT8	v92_c2;
	SINT8	v92_c3;
	SINT8	v92_c4;
	SINT16	v93_c0;
	SINT8	v93_c1;
	SINT8	v93_c2;
	SINT8	v93_c3;
	SINT8	v93_c4;
}CHIP_COMMON_HPF_T;
typedef struct{
	BOOLEAN	Slope_Gain_Enable;
	UINT8	DIR;
	BOOLEAN	FH;
	UINT8	Gain_boundPos;
	UINT8	Gain_boundNeg;
	UINT8	Gain_extendPos;
	UINT8	Gain_extendNeg;
	BOOLEAN	flat_enable;
	UINT8	flat_offset;
	UINT8	flat_gain;
}CHIP_SLOPE_GAIN_MASK_T;

typedef struct{
	BOOLEAN	vpk_en;
	UINT16	vpk_c0;
	SINT16	vpk_c1;
	SINT8	vpk_c2;
	SINT8	vpk_c3;
	SINT8	vpk_c4;
}CHIP_VERTICAL_HPF_T;

typedef struct{
	UINT16	pos_s1;
	UINT16	pos_s2;
	UINT16	pos_s3;
	UINT16	pos_s4;
	UINT16	pos_s5;
	UINT16	pos_s6;
	UINT16	pos_s7;
	UINT16	pos_s8;
	UINT16	pos_s9;
	UINT16	pos_s10;
	UINT16	pos_s11;
	UINT16	pos_s12;
	UINT16	pos_s13;
	UINT16	pos_s14;
	UINT16	neg_s1;
	UINT16	neg_s2;
	UINT16	neg_s3;
	UINT16	neg_s4;
	UINT16	neg_s5;
	UINT16	neg_s6;
	UINT16	neg_s7;
	UINT16	neg_s8;
	UINT16	neg_s9;
	UINT16	neg_s10;
	UINT16	neg_s11;
	UINT16	neg_s12;
	UINT16	neg_s13;
	UINT16	neg_s14;
}CHIP_VERTICAL_CURVEMAPPING_STEP_T;

typedef struct{
	UINT8	Gain_Pos;
	UINT8	Gain_Neg;
	UINT8	Coring;
	UINT8	Gain_Pos2;
	UINT8	Gain_Neg2;
	UINT8	Range_Pos;
	UINT8	Range_Neg;
	BOOLEAN	 V_Parameters_En;
	UINT8	Edge_Gain_Pos;
	UINT8	Edge_Gain_Neg;
	UINT8	Edge_Coring;
	UINT8	Edge_Gain_Pos2;
	UINT8	Edge_Gain_Neg2;
	UINT16	Edge_Range_Pos;
	UINT16	Edge_Range_Neg;
	BOOLEAN v_tex_en;
	BOOLEAN v_dering_en;
	BOOLEAN	enable;
	UINT16	pos_g0;
	UINT16	pos_g1;
	UINT16	pos_g2;
	UINT16	pos_g3;
	UINT16	pos_g4;
	UINT16	pos_g5;
	UINT16	pos_g6;
	UINT16	pos_g7;
	UINT16	pos_g8;
	UINT16	pos_g9;
	UINT16	pos_g10;
	UINT16	pos_g11;
	UINT16	pos_g12;
	UINT16	pos_g13;
	UINT16	pos_g14;
	UINT16	neg_g0;
	UINT16	neg_g1;
	UINT16	neg_g2;
	UINT16	neg_g3;
	UINT16	neg_g4;
	UINT16	neg_g5;
	UINT16	neg_g6;
	UINT16	neg_g7;
	UINT16	neg_g8;
	UINT16	neg_g9;
	UINT16	neg_g10;
	UINT16	neg_g11;
	UINT16	neg_g12;
	UINT16	neg_g13;
	UINT16	neg_g14;
}CHIP_VERTICAL_CURVEMAPPING_UI_T;

typedef struct{
	BOOLEAN Slope_Gain_V_Enable;
	UINT8	DIR;
	UINT8	Gain_boundPos;
	UINT8	Gain_boundNeg;
	UINT8	Gain_extendPos;
	UINT8	Gain_extendNeg;
	BOOLEAN	flat_v_enable;
	UINT8	flat_offset_v;
	UINT8	flat_gain_v;
}CHIP_VERTICAL_SLOPE_GAIN_MASK_T;

typedef struct{
	BOOLEAN	gain_by_y_en;
	BOOLEAN	gain_by_y_v_en;
	BOOLEAN	gain_by_y_tex_en;
	BOOLEAN	gain_by_y_edg_en;
	BOOLEAN	lpf_weight_en;
	BOOLEAN	lpf_weight_edg_en;
	BOOLEAN	lpf_weight_tex_en;
	BOOLEAN	max_min_gain_en;
	BOOLEAN	max_min_v_en;
	BOOLEAN	max_min_tex_en;
	BOOLEAN	max_min_edg_en;
	BOOLEAN	lv_by_Y_enable;
	BOOLEAN	lv_by_y_edg_enable;
	BOOLEAN	lv_by_y_v_edg_enable;
	BOOLEAN	lv_by_y_tex_enable;
	BOOLEAN	lv_by_y_v_enable;


	UINT8	coef_c0;
	UINT8	coef_c1;
	UINT8	coef_c2;
	UINT8	coef_c3;
	UINT8	coef_c4;
	UINT8	coef_c5;

	UINT16	maxmin_s1;
	UINT16	maxmin_s2;
	UINT16	maxmin_s3;
	UINT16	maxmin_s4;
	UINT16	maxmin_s5;
	UINT16	maxmin_s6;

	UINT16	maxmin_g0;
	UINT16	maxmin_g1;
	UINT16	maxmin_g2;
	UINT16	maxmin_g3;
	UINT16	maxmin_g4;
	UINT16	maxmin_g5;
	UINT16	maxmin_g6;

	UINT16	blending_s1;
	UINT16	blending_s2;
	UINT16	blending_s3;
	UINT16	blending_s4;
	UINT16	blending_s5;
	UINT16	blending_s6;

	UINT16	blending_g0;
	UINT16	blending_g1;
	UINT16	blending_g2;
	UINT16	blending_g3;
	UINT16	blending_g4;
	UINT16	blending_g5;
	UINT16	blending_g6;

	UINT16	y_s1;
	UINT16	y_s2;
	UINT16	y_s3;
	UINT16	y_s4;
	UINT16	y_s5;
	UINT16	y_s6;

	UINT16	y_g0;
	UINT16	y_g1;
	UINT16	y_g2;
	UINT16	y_g3;
	UINT16	y_g4;
	UINT16	y_g5;
	UINT16	y_g6;
}CHIP_MKIII_T;


typedef struct {
	BOOLEAN	i_dcti_enable;
	BOOLEAN	i_dcti_uv_sync_enable;
	BOOLEAN	i_dcti_uv_align_enable;
	UINT8	i_dcti_mode;
	UINT8	i_dcti_gain;
	UINT8	i_dcti_Max_search_range;
	UINT8	i_dcti_Threshold_of_smooth;
	BOOLEAN	d_dcti_enable;
	BOOLEAN	d_dcti_uv_sync_enable;
	BOOLEAN	d_dcti_uv_align_enable;
	UINT8	d_dcti_mode;
	UINT8	d_dcti_gain;
	UINT8	d_dcti_Max_search_range;
	UINT8	d_dcti_Threshold_of_smooth;
	BOOLEAN	vcti_enable;
	UINT8	vcti_type;
	UINT8	vcti_gain;
	UINT8	vcti_type3_thd;
} CHIP_CTI_T;

typedef struct {
	BOOLEAN d_LTI_enable;
	UINT8 d_LTI_can_shift;
	UINT8 d_LTI_maxlen;
	UINT16 d_LTI_pnth;
	BOOLEAN	tn_blend_Enable;
	BOOLEAN	ffd2_Enable;
	UINT8	Data_sel;
	BOOLEAN	tn_blend_mode;
	UINT8	D1_CP_Shift;
	UINT8	DCP_th;
	UINT8	Flat_s_range;
	UINT8	Flat_score_th1;
	UINT16	Ffd1_th;
	UINT8	Ffd1_ratio;
	UINT16	Ffd2_range2R;
	UINT16	Ffd2_range2L;
	UINT8	Ffd2_ratio;
	UINT16	gain_pos;
	UINT16	offset_pos;
	UINT16	gain_neg;
	UINT16	offset_neg;
	UINT8	Tnoff0;
	UINT8	Tnoff1;
	UINT8	Tnoff2;
	UINT8	Tnoff3;
	UINT8	Tnoff4;
	UINT8	Tnoff5;
	UINT8	Tnoff6;
	UINT8	Tnoff7;
	UINT8	Tnoff8;
	UINT8	Tnoff9;
	UINT8	Tnoff10;
	UINT8	Tnoff11;
	UINT8	Tnoff12;
	UINT8	Tnoff13;
	UINT8	Tnoff14;
}CHIP_HLTI_T;

typedef struct{
	BOOLEAN d_LTI_enable;
	UINT8	Can_shift_v;
	UINT8	maxlen_v;
	UINT16	pnth_v;
	UINT16	ffd1_th_v;
	UINT8	ffd1_ratio_v;
	UINT16	gain_pos_v;
	UINT16	offset_pos_v;
	UINT16	gain_neg_v;
	UINT16	offset_neg_v;
	UINT8	Tnoff0_v;
	UINT8	Tnoff1_v;
	UINT8	Tnoff2_v;
	UINT8	Tnoff3_v;
	UINT8	Tnoff4_v;
	UINT8	Tnoff5_v;
	UINT8	Tnoff6_v;
}CHIP_VLTI_T;

typedef struct{
	BOOLEAN ise_en;
	UINT8	ise_step;
	UINT8	ise_scale;
	UINT8	ise_ub;
	UINT8	ise_h_st;
	UINT8	ise_h_end;
	BOOLEAN ise_v_st;
	UINT8	ise_v_end;
}CHIP_ISE_T;

typedef struct{
	BOOLEAN tex_flat_filter_en;
	UINT8	coef_c0_2;
	UINT8	coef_c0_1;
	UINT16	coef_c0_0;
	UINT8	coef_c1_0;
	UINT8	coef_c2_0;
	UINT8	coef_c3_0;
}CHIP_FLAT_FILTER_T;

typedef struct{
	BOOLEAN Maxmin_Limit_En;
	UINT8	Maxmin_Shift;
	UINT8	sr_var_thd;
	BOOLEAN Maxmin_Mode;
	BOOLEAN Maxmin_Range;
	UINT8	Maxmin_Thd;
	BOOLEAN Edge_Range;
	UINT8	Delta_Gain;
	BOOLEAN LPF_Range;
	BOOLEAN lpf_range_en;
	UINT8	lpf_range_thd;
	UINT8	lpf_range_gain;
	UINT8	lpf_range_step;
	UINT8	lpf_gain;
	BOOLEAN lpf_edge_en;
	UINT8	lpf_edge_thd;
	UINT8	lpf_edge_gain;
	UINT8	lpf_edge_step;
	BOOLEAN bif_range_en;
	UINT8	bif_thd0;
	UINT8	bif_thd1;
	UINT8	bif_thd2;
	UINT8	bif_thd3;
	UINT8	bif_thd4;
	UINT8	bif_thd5;
	UINT8	bif_thd6;
	UINT8	bif_thd7;
	UINT8	bif_range_thd0;
	UINT8	bif_range_thd1;
	UINT8	bif_range_gain0;
	UINT8	bif_range_gain1;
	UINT8	bif_range_step0;
	UINT8	bif_range_step1;
	UINT8	bif_gain;
	BOOLEAN bif_edge_en;
	UINT8	bif_edge_thd;
	UINT8	bif_edge_gain;
	UINT8	bif_edge_step;
	BOOLEAN by_gain_en;
	BOOLEAN diffdir_cond_e;
	UINT8	pgain0;
	UINT8	pgain1;
	UINT8	pgain2;
	UINT8	pgain3;
	UINT8	pgain4;
	UINT8	pgain5;
	UINT8	pgain6;
	UINT8	pgain7;
	UINT8	pgain8;
	UINT8	ngain0;
	UINT8	ngain1;
	UINT8	ngain2;
	UINT8	ngain3;
	UINT8	ngain4;
	UINT8	ngain5;
	UINT8	ngain6;
	UINT8	ngain7;
	UINT8	ngain8;
}CHIP_SECOND_SR_T;



typedef struct {
	BOOLEAN mb_peaking_en;
	UINT16 h_c0;
	SINT16 h_c1;
	SINT8 h_c2;
	SINT8 h_c3;
	SINT8 h_c4;
	SINT8 h_c5;
	SINT8 h_c6;
	UINT16 v_c0;
	SINT16 v_c1;
	SINT8 v_c2;
} CHIP_MULTIBAND_PEAKING_HPF_T;

typedef struct {
	BOOLEAN mb_h_en;
	UINT8 H_Gain_Pos;
	UINT8 H_Gain_Neg;
	UINT8 H_Coring;
	UINT8 H_Gain_Pos2;
	UINT8 H_Gain_Neg2;
	UINT16 H_Range_Pos;
	UINT16 H_Range_Neg;
	UINT8 H_Edge_Shift;
	BOOLEAN mb_v_en;
	UINT8 V_Gain_Pos;
	UINT8 V_Gain_Neg;
	UINT8 V_Coring;
	UINT8 V_Gain_Pos2;
	UINT8 V_Gain_Neg2;
	UINT16 V_Range_Pos;
	UINT16 V_Range_Neg;
	UINT8 V_Edge_Shift;
} CHIP_MULTIBAND_PEAKING_UI_T;

typedef struct {
	CHIP_SEGMENTATION_T		stSegmentation;
	CHIP_EDGE_CORING_MODE_T	stEdgeCoringMode;
	CHIP_Y_REMAPPING_T		stYRemapping;
	CHIP_EDGE_HPF_T			stEdgeHPF;
	CHIP_EDGE_CURVEMAPPING_STEP_T	stEdgeCurveMappingStep;
	CHIP_EDGE_CURVEMAPPING_UI_T		stEdgeCurveMappingUI;
	CHIP_TEXTURE_HPF_T				stTextureHPF;
	CHIP_TEXTURE_CURVEMAPPING_STEP_T	stTextureCurveMappingStep;
	CHIP_TEXTURE_CURVEMAPPING_UI_T		stTextureCurveMappingUI;
	CHIP_COMMON_HPF_T	stCommonHPF;
	CHIP_SLOPE_GAIN_MASK_T	stSlopeGainMask;
	CHIP_VERTICAL_HPF_T		stVerticalHPF;
	CHIP_VERTICAL_CURVEMAPPING_STEP_T	stVerticalCurveMappingStep;
	CHIP_VERTICAL_CURVEMAPPING_UI_T		stVerticalCurveMappingUI;
	CHIP_VERTICAL_SLOPE_GAIN_MASK_T	stVerticalSlopeGainMask;
	CHIP_MKIII_T	stMKIII;
	CHIP_CTI_T		stCTI;
	CHIP_HLTI_T	stHLTI;
	CHIP_VLTI_T	stVLTI;
	CHIP_MULTIBAND_PEAKING_HPF_T	stMultibandPeakingHPF;
	CHIP_MULTIBAND_PEAKING_UI_T	stMultibandPeakingUI;
	CHIP_ISE_T	stIse;
	CHIP_FLAT_FILTER_T	stFlatfilter;
	CHIP_SECOND_SR_T	stSecondSr;
} CHIP_SHARPNESS_T;

typedef struct{
	SINT16	ring_h_c0;
	SINT8	ring_h_c1;
	SINT8	ring_h_c2;
	SINT8	ring_h_c3;
	SINT8	ring_h_c4;
	SINT8	ring_h_c5;
	SINT16	ring_v_c0;
	SINT8	ring_v_c1;
	SINT8	ring_v_c2;
	SINT8	ring_v_c3;
	SINT8	ring_v_c4;
	UINT8	edge_filter_sel;
	UINT8	tex_filter_sel;
	UINT8	Ring_Gen_Gain;
	UINT8	Cur_Period;
	UINT16	Cur_Gain;
	UINT16	Cur_Offset;
	UINT8	Ring_Gen_Type;
	UINT8	Filter_Type;
}CHIP_SUPER_RESOLUTION_T;

typedef struct{
	BOOLEAN	emf_enable;
	UINT8	emf_range;
	UINT8	emf_shiftbit;
	UINT8	blend_wt;
	UINT8	fix_extend_pos;
	UINT8	fix_extend_neg;
	UINT16	seg0_x;
	UINT16	seg1_x;
	UINT8	gain0;
	UINT8	gain1;
	UINT8	gain2;
	UINT16	Offset0;
}CHIP_EDGE_EMF_UI_T;

typedef struct{
	BOOLEAN	emf_enable;
	UINT8	emf_range;
	UINT8	emf_shiftbit;
	UINT8	blend_wt;
	UINT8	fix_extend_pos;
	UINT8	fix_extend_neg;
	UINT16	seg0_x;
	UINT16	seg1_x;
	UINT8	gain0;
	UINT8	gain1;
	UINT8	gain2;
	UINT16	Offset0;
}CHIP_TEXTURE_EMF_UI_T;

typedef struct{
	BOOLEAN	vemf_en;
	UINT8	vext_reg;
}CHIP_VERTICAL_EMF_UI_T;

typedef struct{
	CHIP_EDGE_EMF_UI_T	stEdgeEMF;
	CHIP_TEXTURE_EMF_UI_T	stTextureEMF;
	CHIP_VERTICAL_EMF_UI_T	stVerticalEMF;
}CHIP_EDGE_ENHANCE_T;

/**********************************************************************
	GAMUT
***********************************************************************/
typedef struct{
	UINT8 		invgamma_enable;	// inverse gamma & gamma enable,  0: disable, 1: enable
	SINT16		gamutmatrix_00;		// 3x3 matrix
	SINT16		gamutmatrix_01;
	SINT16		gamutmatrix_02;
	SINT16		gamutmatrix_10;
	SINT16		gamutmatrix_11;
	SINT16		gamutmatrix_12;
	SINT16		gamutmatrix_20;
	SINT16		gamutmatrix_21;
	SINT16		gamutmatrix_22;
	BOOLEAN 	b3DLUT_enable;		// 3D LUT,  0: disable, 1: enable
	UINT8		u3DLUT_index;		// 3D LUT table index number
	BOOLEAN 	b3DLUT_internalselect;
} CHIP_GAMUT_T;


typedef struct{
	UINT8	M_LC_Comp_En;	//Master enable
	UINT8	LC_Tone_Mapping_En;	//Tone Mapping enable
	UINT8	LC_tmap_slope_unit;	//slope (0, 1)
	UINT8	LC_tmap_blend_factor;	//blend (0~255)
	UINT8	LC_tmap_curve_Grid[8];	// Grid setting
	UINT16	LC_tmap_curve_tone[8];	// Tone setting
	UINT16	LC_ToneMappingSlopePont_Table[256];	// Tone Mapping curve data (8 curves)
} CHIP_LOCAL_CONTRAST_T;


/**
 *	structure for HAL_VPQ_LED_LDSetDBLUT
 */

typedef struct
{
     unsigned char hal_ld_maxgain;
     unsigned char hal_ld_avergain;
     unsigned char hal_ld_histshiftbit;
     unsigned char hal_ld_hist0gain;
     unsigned char hal_ld_hist1gain;
     unsigned char hal_ld_hist2gain;
     unsigned char hal_ld_hist3gain;
     unsigned char hal_ld_hist4gain;
     unsigned char hal_ld_hist5gain;
     unsigned char hal_ld_hist6gain;
     unsigned char hal_ld_hist7gain;
} HAL_LED_BACKLIGHT_DECISION;

typedef struct
{
     unsigned char hal_ld_spatialnewcoef00;
     unsigned char hal_ld_spatialnewcoef01;
     unsigned char hal_ld_spatialnewcoef02;
     unsigned char hal_ld_spatialnewcoef03;
     unsigned char hal_ld_spatialnewcoef04;
     unsigned char hal_ld_spatialnewcoef05;
     unsigned char hal_ld_spatialnewcoef10;
     unsigned char hal_ld_spatialnewcoef11;
     unsigned char hal_ld_spatialnewcoef12;
     unsigned char hal_ld_spatialnewcoef13;
     unsigned char hal_ld_spatialnewcoef14;
     unsigned char hal_ld_spatialnewcoef15;
} HAL_LED_SPATIAL_FILTER;

typedef struct
{
     unsigned char hal_ld_temp_pos0thd;
     unsigned char hal_ld_temp_pos1thd;;
     unsigned char hal_ld_temp_posmingain;
     unsigned char hal_ld_temp_posmaxgain;
     unsigned char hal_ld_temp_neg0thd;
     unsigned char hal_ld_temp_neg1thd;
     unsigned char hal_ld_temp_nedmingain;
     unsigned char hal_ld_temp_negmaxgain;
     unsigned char hal_ld_temp_maxdiff;
     unsigned char hal_ld_temp_scenechangegain1;
} HAL_LED_TEMPORAL_FILTER;

typedef struct
{
     unsigned char hal_ld_spatialremapen;
     unsigned short hal_ld_spatialremaptab[65];
} HAL_LED_REMAP_CURVE;

typedef struct
{
     unsigned int al_ld_comp_2Dtable[17][17];
}HAL_LED_DATA_COMP;

typedef struct
{
     UINT8 LD_UI_Index;
     HAL_LED_BACKLIGHT_DECISION hal_backlight_decision;
     HAL_LED_SPATIAL_FILTER hal_spatial_filter;
     HAL_LED_TEMPORAL_FILTER hal_temporal_filter;
     HAL_LED_REMAP_CURVE hal_remap_curve;
     HAL_LED_DATA_COMP hal_data_comp_table;
} HAL_LED_DB_LUT_T;

typedef struct CHIP_CSC_COEFF
{
    UINT32 chipData;
}
CHIP_CSC_COEFF_T;

/**
 *	set preferred color type
 */
typedef struct
{
	CHIP_COLOR_GAIN_T stColor[CHIP_CM_COLOR_REGION_MAX];
}
CHIP_COLOR_CONTROL_T;

#endif	/* _HAL_VPQ_DEF_H_ */
