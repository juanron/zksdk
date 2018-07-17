#ifndef _libzkfptype_h
#define _libzkfptype_h

/**
*	@file		libzkfptype.h
*	@brief		结构体定义
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


#include "zkinterface.h"

#define FP_THRESHOLD_CODE		1	/**<	指纹1:1阀值 */
#define FP_MTHRESHOLD_CODE		2	/**<	指纹1:N阀值 */
#ifndef MAX_TEMPLATE_SIZE
#define MAX_TEMPLATE_SIZE 2048		/**<	模板最大长度 */
#endif

/** 
   * @brief 采集图像信息
*/
typedef struct _ZKFPCapParams
{
	unsigned int imgWidth;					/**< 图像宽 */
	unsigned int imgHeight;					/**< 图像高 */
	unsigned int nDPI;						/**< 图像DPI（500） */
}TZKFPCapParams, *PZKFPCapParams;


#endif	//_libzkfptype_h