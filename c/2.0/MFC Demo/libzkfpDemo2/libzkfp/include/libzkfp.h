#ifndef _libzkfp_h
#define _libzkfp_h
/**
*	@file		libzkfp.h
*	@brief		接口定义
*	@author		scar chen
*	@date		2016-04-12
*	@version	5.0
*	@par	版权：
*				ZKTeco
*	@par	历史版本			
*
*	@note
*
*/


#include "libzkfptype.h"


#ifdef __cplusplus
extern "C"
{
#endif

/**
	*	@brief	初始化库
	*	@param	:
	*		无
	*	@return
	*	返回值说明如下：
	*	value			|	type		|	description of value
	*	----------------|---------------|-------------------------------
	*	0				|	int			|	成功
	*	其他			|	int			|	失败
	*	@note 
*/
ZKINTERFACE int APICALL ZKFPM_Init();

/**
	*	@brief	释放库
	*	@param	:
	*		无
	*	@return
	*	返回值说明如下：
	*	value			|	type		|	description of value
	*	----------------|---------------|-------------------------------
	*	0				|	int			|	成功
	*	其他			|	int			|	失败
	*	@note 
*/
ZKINTERFACE int APICALL ZKFPM_Terminate();

/**
	*	@brief	获取设备数
	*	@param	:
	*		无
	*	@return
	*	返回值说明如下：
	*		当前接入指静脉仪设备数
	*	@note 
*/
ZKINTERFACE int APICALL ZKFPM_GetDeviceCount();


/**
		*	@brief	打开设备
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	index			|	int			  |	[in]				|	设备索引
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	NULL			|	HANDLE		|	失败
		*	其他			|	HANDLE		|	成功
		*	@note 
	*/
	ZKINTERFACE HANDLE APICALL ZKFPM_OpenDevice(int index);

	/**
		*	@brief	关闭设备
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDevice			|	HANDLE		  |	[in]				|	设备操作实例指针
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_CloseDevice(HANDLE hDevice);

	

	/**
		*	@brief	设置参数
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDevice			|	HANDLE		  |	[in]				|	设备操作实例指针
		*	nParamCode		|	int			  |	[in]				|	参数类型
		*	paramValue		|	unsigned char*|	[in]				|	参数值
		*	cbParamValue	|	unsigned int  |	[in]				|	参数数据长度
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_SetParameters(HANDLE hDevice, int nParamCode, unsigned char* paramValue, unsigned int cbParamValue);

	/**
		*	@brief	获取参数
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDevice			|	HANDLE		  |	[in]				|	设备操作实例指针
		*	nParamCode		|	int			  |	[in]				|	参数类型
		*	paramValue		|	unsigned char*|	[out]				|	参数值
		*	cbParamValue	|	unsigned int* |	[out]				|	参数数据长度
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_GetParameters(HANDLE hDevice, int nParamCode, unsigned char* paramValue, unsigned int* cbParamValue);
	
	/**
		*	@brief	获取指纹(图像/模板）
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDevice			|	HANDLE		  |	[in]				|	设备操作实例指针
		*	fpImage			|	unsigned char*|	[out]				|	指纹图像
		*	cbFPImage		|	unsigned int  |	[in]				|	fpImage内存大小
		*	fpTemplate		|	unsigned char*|	[out]				|	指纹模板
		*	cbTemplate		|	unsigned int* |	[in/out]			|	指纹模板长度
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_AcquireFingerprint(HANDLE hDevice, unsigned char* fpImage, unsigned int cbFPImage, unsigned char* fpTemplate, unsigned int* cbTemplate);


	/**
		*	@brief	获取指纹图像
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDevice			|	HANDLE		  |	[in]				|	设备操作实例指针
		*	fpImage			|	unsigned char*|	[out]				|	指纹图像
		*	cbFPImage		|	unsigned int  |	[in]				|	fpImage内存大小
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_AcquireFingerprintImage(HANDLE hDevice, unsigned char* fpImage, unsigned int cbFPImage);

	/**
		*	@brief	创建算法操作实例
		*	@param	:
		*	无
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	NULL			|	HANDLE		|	失败
		*	其他			|	HANDLE		|	成功
		*	@note 
	*/
	ZKINTERFACE HANDLE APICALL ZKFPM_CreateDBCache();
	ZKINTERFACE HANDLE APICALL ZKFPM_DBInit();	//same as ZKFPM_CreateDBCache, for new version
	/**
		*	@brief	释放算法操作实例
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDBCache		|	HANDLE		  |	[in]				|	算法操作实例指针
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_CloseDBCache(HANDLE hDBCache);
	ZKINTERFACE int APICALL ZKFPM_DBFree(HANDLE hDBCache); //same as ZKFPM_CloseDBCache, for new version

	ZKINTERFACE int APICALL ZKFPM_DBSetParameter(HANDLE hDBCache, int nParamCode, unsigned char* paramValue, unsigned int cbParamValue);
	ZKINTERFACE int APICALL ZKFPM_DBGetParameter(HANDLE hDBCache, int nParamCode, unsigned char* paramValue, unsigned int cbParamValue);


	/**
		*	@brief	将3个指纹模板合成登记模板
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDBCache		|	HANDLE		  |	[in]				|	算法操作实例指针
		*	temp1			|	unsigned char*|	[in]				|	指纹模板1
		*	temp2			|	unsigned char*|	[in]				|	指纹模板2
		*	temp3			|	unsigned char*|	[in]				|	指纹模板3
		*	regTemp			|	unsigned char*|	[out]				|	登记模板
		*	cbRegTemp		|	unsigned int* |	[in/out]			|	登记模板长度
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_GenRegTemplate(HANDLE hDBCache, unsigned char* temp1, unsigned char* temp2, unsigned char* temp3, unsigned char* regTemp, unsigned int* cbRegTemp);
	ZKINTERFACE int APICALL ZKFPM_DBMerge(HANDLE hDBCache, unsigned char* temp1, unsigned char* temp2, unsigned char* temp3, unsigned char* regTemp, unsigned int* cbRegTemp);	//same as ZKFPM_GenRegTemplate, for new version
		
	/**
		*	@brief	添加指纹模板到缓存
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDBCache		|	HANDLE		  |	[in]				|	算法操作实例指针
		*	fid				|	unsigned int  |	[in]				|	手指ID
		*	fpTemplate		|	unsigned char*|	[in]				|	指纹模板
		*	cbTemplate		|	unsigned int  |	[in]				|	指纹模板长度
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_AddRegTemplateToDBCache(HANDLE hDBCache, unsigned int fid, unsigned char* fpTemplate, unsigned int cbTemplate);
	ZKINTERFACE int APICALL ZKFPM_DBAdd(HANDLE hDBCache, unsigned int fid, unsigned char* fpTemplate, unsigned int cbTemplate);	//same as ZKFPM_AddRegTemplateToDBCache, for new version

	/**
		*	@brief	从缓存删除指纹模板
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDBCache		|	HANDLE		  |	[in]				|	算法操作实例指针
		*	fid				|	unsigned int  |	[in]				|	手指ID
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_DelRegTemplateFromDBCache(HANDLE hDBCache, unsigned int fid);
	ZKINTERFACE int APICALL ZKFPM_DBDel(HANDLE hDBCache, unsigned int fid);			//same as ZKFPM_DelRegTemplateFromDBCache, for new version
	

	/**
		*	@brief	清空算法缓存
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDBCache		|	HANDLE		  |	[in]				|	算法操作实例指针
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_ClearDBCache(HANDLE hDBCache);
	ZKINTERFACE int APICALL ZKFPM_DBClear(HANDLE hDBCache);	//same as ZKFPM_ClearDBCache, for new version

	/**
		*	@brief	获取缓存模板数
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDBCache		|	HANDLE		  |	[in]				|	算法操作实例指针
		*	fpCount			|	unsigned int* |	[out]				|	指纹模板数
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_GetDBCacheCount(HANDLE hDBCache, unsigned int* fpCount);
	ZKINTERFACE int APICALL ZKFPM_DBCount(HANDLE hDBCache, unsigned int* fpCount);	//same as ZKFPM_GetDBCacheCount, for new version


	/**
		*	@brief	指纹识别(1:N)
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDBCache		|	HANDLE		  |	[in]				|	算法操作实例指针
		*	fpTemplate		|	unsigned char*|	[in]				|	指纹模板
		*	cbTemplate		|	unsigned int  | [in]				|	指纹模板大小
		*	FID				|	unsigned int* |	[out]				|	指静脉ID
		*	score			|	unsigned int* |	[out]				|	分数
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_Identify(HANDLE hDBCache, unsigned char* fpTemplate, unsigned int cbTemplate, unsigned int* FID, unsigned int* score);
	ZKINTERFACE int APICALL ZKFPM_DBIdentify(HANDLE hDBCache, unsigned char* fpTemplate, unsigned int cbTemplate, unsigned int* FID, unsigned int* score);	//same as ZKFPM_Identify, for new version


	/**
		*	@brief	比对两枚指纹
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDBCache		|	HANDLE		  |	[in]				|	算法操作实例指针
		*	template1		|	unsigned char*|	[in]				|	指纹模板1
		*	cbTemplate1		|	unsigned int  | [in]				|	指纹模板1大小
		*	template2		|	unsigned char*|	[in]				|	指纹模板2
		*	cbTemplate2		|	unsigned int  | [in]				|	指纹模板2大小
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	>0				|	int			|	分数
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_MatchFinger(HANDLE hDBCache, unsigned char* template1, unsigned int cbTemplate1, unsigned char* template2, unsigned int cbTemplate2);
	ZKINTERFACE int APICALL ZKFPM_DBMatch(HANDLE hDBCache, unsigned char* template1, unsigned int cbTemplate1, unsigned char* template2, unsigned int cbTemplate2); //same as ZKFPM_MatchFinger, for new version

	/**
		*	@brief	从Bitmap文件提取指纹模板
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDBCache		|	HANDLE		  |	[in]				|	算法操作实例指针
		*	lpFilePathName	|	const char*   |	[in]				|	BMP图片路径
		*	DPI				|	unsigned int  | [in]				|	BMP图片DPI
		*	fpTemplate		|	unsigned char*|	[out]				|	指纹模板
		*	cbTemplate		|	unsigned int* |	[in/out]			|	模板长度
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	>0				|	int			|	分数
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_ExtractFromImage(HANDLE hDBCache, const char* lpFilePathName, unsigned int DPI, unsigned char* fpTemplate, unsigned int *cbTemplate);


	/**
		*	@brief	Base64字符串转二进制数据
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	src				|	const char*	  |	[in]				|	Base64字符串
		*	blob			|	unsigned char*|	[out]				|	返回二进制数据
		*	cbBlob			|	unsigned int  |	[in]				|	blob内存大小
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	>0表示数据长度；<=0表示失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_Base64ToBlob(const char* src, unsigned char* blob, unsigned int cbBlob);

	/**
		*	@brief	二进制数据转Base64字符串
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	src				|const unsigned char*|	[in]			|	二进制数据
		*	cbSrc			|	unsigned int  |	[in]				|	二进制数据长度
		*	base64Str		|	char *		  |	[out]				|	返回Base64字符串
		*	cbBase64str		|	unsigned int  | [int]				|	base64Str分配内存大小
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	>0表示数据长度；<=0表示失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_BlobToBase64(const unsigned char* src, unsigned int cbSrc, char* base64Str, unsigned int cbBase64str);


	/**
		*	@brief	1:1比对用户指纹
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDBCache		|	HANDLE		  |	[in]				|	算法操作实例指针
		*	fpTemplate		|	unsigned char*|	[in]				|	指纹模板
		*	cbTemplate		|	unsigned int  | [in]				|	指纹模板大小
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	>0				|	int			|	分数
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_VerifyByID(HANDLE hDBCache, unsigned int fid, unsigned char* fpTemplate, unsigned int cbTemplate);

	/**
		*	@brief	获取最后一次外部图像数据指针
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	width			|	int*		  |	[out]				|	图像宽
		*	height			|	int*		  |	[out]				|	图像高
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	图像数据指针，请在ZKFPM_ExtractFromImage成功后获取
		*	@note 
	*/
	ZKINTERFACE unsigned char* APICALL ZKFPM_GetLastExtractImage(int * width, int* height);


	/**
		*	@brief	获取采集参数
		*	@param	:
		*	参数说明如下表
		*	name			|	type		  |	param direction		|	description of param
		*	----------------|-----------------|---------------------|------------------------
		*	hDevice			|	HANDLE		  |	[in]				|	设备操作实例指针
		*	pCapParams		|	PZKFPCapParams|	[out]				|	采集参数
		*	@return
		*	返回值说明如下：
		*	value			|	type		|	description of value
		*	----------------|---------------|-------------------------------
		*	0				|	int			|	成功
		*	其他			|	int			|	失败
		*	@note 
	*/
	ZKINTERFACE int APICALL ZKFPM_GetCaptureParams(HANDLE hDevice, PZKFPCapParams pCapParams);

	ZKINTERFACE int APICALL ZKFPM_GetCaptureParamsEx(HANDLE hDevice, int* width, int* height, int* dpi);

#ifdef __cplusplus
};
#endif


#endif	//_libzkfp_h