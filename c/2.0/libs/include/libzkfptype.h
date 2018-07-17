#ifndef _libzkfptype_h
#define _libzkfptype_h

/**
*	@file		libzkfptype.h
*	@brief		�ṹ�嶨��
*	@author		scar chen
*	@date		2016-04-12
*	@version	5.0
*	@par	��Ȩ��
*				ZKTeco
*	@par	��ʷ�汾			
*
*	@note
*
*/


#include "zkinterface.h"

#define FP_THRESHOLD_CODE		1	/**<	ָ��1:1��ֵ */
#define FP_MTHRESHOLD_CODE		2	/**<	ָ��1:N��ֵ */
#ifndef MAX_TEMPLATE_SIZE
#define MAX_TEMPLATE_SIZE 2048		/**<	ģ����󳤶� */
#endif

/** 
   * @brief �ɼ�ͼ����Ϣ
*/
typedef struct _ZKFPCapParams
{
	unsigned int imgWidth;					/**< ͼ��� */
	unsigned int imgHeight;					/**< ͼ��� */
	unsigned int nDPI;						/**< ͼ��DPI��500�� */
}TZKFPCapParams, *PZKFPCapParams;


#endif	//_libzkfptype_h