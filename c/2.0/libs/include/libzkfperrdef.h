#ifndef _libzkfperrdef_h
#define _libzkfperrdef_h


/**
*	@file		libzkfperrdef.h
*	@brief		�����붨��
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


#define ZKFP_ERR_ALREADY_INIT	1	/**<	�Ѿ���ʼ�� */
#define ZKFP_ERR_OK			0	/**<	�����ɹ� */
#define ZKFP_ERR_INITLIB	-1	/**<	��ʼ���㷨��ʧ�� */
#define ZKFP_ERR_INIT		-2	/**<	��ʼ���ɼ���ʧ�� */
#define ZKFP_ERR_NO_DEVICE	-3	/**<	���豸���� */
#define ZKFP_ERR_NOT_SUPPORT	-4	/**<	�ӿ��ݲ�֧�� */
#define ZKFP_ERR_INVALID_PARAM	-5	/**<	��Ч���� */
#define ZKFP_ERR_OPEN			-6	/**<	���豸ʧ�� */
#define ZKFP_ERR_INVALID_HANDLE	-7	/**<	��Ч��� */
#define ZKFP_ERR_CAPTURE		-8	/**<	ȡ��ʧ�� */
#define ZKFP_ERR_EXTRACT_FP		-9	/**<	��ȡָ��ģ��ʧ�� */
#define ZKFP_ERR_ABSORT			-10	/**<	�ж� */
#define ZKFP_ERR_MEMORY_NOT_ENOUGH			-11	/**<	�ڴ治�� */
#define ZKFP_ERR_BUSY			-12	/**<	��ǰ���ڲɼ� */
#define ZKFP_ERR_ADD_FINGER		-13	/**<	���ָ��ģ��ʧ�� */
#define ZKFP_ERR_DEL_FINGER		-14	/**<	ɾ��ָ��ʧ�� */
#define ZKFP_ERR_FAIL			-17	/**<	����ʧ�� */
#define ZKFP_ERR_CANCEL			-18	/**<	ȡ���ɼ� */
#define ZKFP_ERR_VERIFY_FP		-20 /**<	�ȶ�ָ��ʧ�� */
#define ZKFP_ERR_MERGE			-22 /**<	�ϲ��Ǽ�ָ��ģ��ʧ��	*/
#define ZKFP_ERR_NOT_OPENED		-23; /**<	�豸δ��	*/
#define ZKFP_ERR_NOT_INIT		-24; /**<	δ��ʼ��	*/
#define ZKFP_ERR_ALREADY_OPENED	-25; /**<	�豸�Ѵ�	*/
#define ZKFP_ERR_LOADIMAGE		-26	/**<	�ļ���ʧ��			*/
#define ZKFP_ERR_ANALYSE_IMG	-27	/**<	����ͼ��ʧ��			*/
#define ZKFP_ERR_TIMEOUT		-28	/**<	��ʱ					*/


#endif	//_libzkfperrdef_h