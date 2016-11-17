/*
 * USB.h
 *
 *  Created on: 2016/11/14
 *      Author: takumi152
 */

#ifndef DEVICE_INC_USB_HPP_
#define DEVICE_INC_USB_HPP_

#include <stdint.h>
#include <string>
#include <vector>
//#include "usb/app_usbd_cfg.h"
#include <text.hpp>
#include<error.h>
#include <stddef.h>
namespace Device {

namespace USB {

#define VCOM_RX_BUF_SZ      512
#define VCOM_TX_CONNECTED   _BIT(8)		/* connection state is for both RX/Tx */
#define VCOM_TX_BUSY        _BIT(0)
#define VCOM_RX_DONE        _BIT(0)
#define VCOM_RX_BUF_FULL    _BIT(1)
#define VCOM_RX_BUF_QUEUED  _BIT(2)
#define VCOM_RX_DB_QUEUED   _BIT(3)

/**
 * Structure containing Virtual Comm port control data
 */

constexpr size_t RxBufferSize=64;//二次バッファの大きさ
constexpr size_t RxTempSize=16;//二次バッファへ移動する際のバッファの大きさ(スタックに乗る)

// TODO USB header stub
void Init();


/**
 * @brief	Virtual com port buffered read routine
 * @param	pBuf	: Pointer to buffer where read data should be copied
 * @param	buf_len	: Length of the buffer passed
 * @return	Return number of bytes read.
 */
uint32_t Bread (uint8_t *pBuf, uint32_t buf_len);

/**
 * @brief	Virtual com port read routine
 * @param	pBuf	: Pointer to buffer where read data should be copied
 * @param	buf_len	: Length of the buffer passed
 * @return	Always returns LPC_OK.
 */
ErrorCode_t Read_req (uint8_t *pBuf, uint32_t buf_len);

/**
 * @brief	Gets current read count.
 * @return	Returns current read count.
 */
uint32_t Read_cnt(void);

/**
 * @brief	Check if Vcom is connected
 * @return	Returns non-zero value if connected.
 */
/*
static INLINE uint32_t Connected(void) {
	return g_vCOM.tx_flags & VCOM_TX_CONNECTED;
}
*/
/**
 * @brief	Virtual com port write routine
 * @param	pBuf	: Pointer to buffer to be written
 * @param	buf_len	: Length of the buffer passed
 * @return	Number of bytes written
 */
uint32_t Write (uint8_t *pBuf, uint32_t buf_len);

/**
 * @}
 */

//自作関数群
bool IsConnected();
uint32_t GetDepth();//受信文字数
bool IsEmpty();

static inline uint32_t Write(const std::string& text){
return Write((uint8_t*)text.data(),text.length());
}

static inline uint32_t WriteLine(const std::string& text){
	return Write(text+common::newline);
}

static inline uint32_t Write(char c){//非推奨
	return Write((uint8_t*)&c,sizeof(c));
}

char ReadByte();
std::string Read();



}

}

#endif /* DEVICE_INC_USB_HPP_ */