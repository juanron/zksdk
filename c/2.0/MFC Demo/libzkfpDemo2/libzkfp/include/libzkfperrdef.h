#ifndef _libzkfperrdef_h
#define _libzkfperrdef_h


/**
*	@file		libzkfperrdef.h
*	@brief		错误码定义
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


#define ZKFP_ERR_ALREADY_INIT	1	/**<	已经初始化 */
#define ZKFP_ERR_OK			0	/**<	操作成功 */
#define ZKFP_ERR_INITLIB	-1	/**<	初始化算法库失败 */
#define ZKFP_ERR_INIT		-2	/**<	初始化采集库失败 */
#define ZKFP_ERR_NO_DEVICE	-3	/**<	无设备连接 */
#define ZKFP_ERR_NOT_SUPPORT	-4	/**<	接口暂不支持 */
#define ZKFP_ERR_INVALID_PARAM	-5	/**<	无效参数 */
#define ZKFP_ERR_OPEN			-6	/**<	打开设备失败 */
#define ZKFP_ERR_INVALID_HANDLE	-7	/**<	无效句柄 */
#define ZKFP_ERR_CAPTURE		-8	/**<	取像失败 */
#define ZKFP_ERR_EXTRACT_FP		-9	/**<	提取指纹模板失败 */
#define ZKFP_ERR_ABSORT			-10	/**<	中断 */
#define ZKFP_ERR_MEMORY_NOT_ENOUGH			-11	/**<	内存不足 */
#define ZKFP_ERR_BUSY			-12	/**<	当前正在采集 */
#define ZKFP_ERR_ADD_FINGER		-13	/**<	添加指纹模板失败 */
#define ZKFP_ERR_DEL_FINGER		-14	/**<	删除指纹失败 */
#define ZKFP_ERR_FAIL			-17	/**<	操作失败 */
#define ZKFP_ERR_CANCEL			-18	/**<	取消采集 */
#define ZKFP_ERR_VERIFY_FP		-20 /**<	比对指纹失败 */
#define ZKFP_ERR_MERGE			-22 /**<	合并登记指纹模板失败	*/
#define ZKFP_ERR_NOT_OPENED		-23; /**<	设备未打开	*/
#define ZKFP_ERR_NOT_INIT		-24; /**<	未初始化	*/
#define ZKFP_ERR_ALREADY_OPENED	-25; /**<	设备已打开	*/
#define ZKFP_ERR_LOADIMAGE		-26	/**<	文件打开失败			*/
#define ZKFP_ERR_ANALYSE_IMG	-27	/**<	处理图像失败			*/
#define ZKFP_ERR_TIMEOUT		-28	/**<	超时					*/


#endif	//_libzkfperrdef_h