package com.zkteco.util;

import java.io.IOException;

/**
 * @author yuyi.liu
 *
 */
public interface DataHandleCallback {

	public Object doReadHandle(byte[]bytes) throws IOException;
	public byte[] doWriteHandle(Object bean)throws IOException;
}
