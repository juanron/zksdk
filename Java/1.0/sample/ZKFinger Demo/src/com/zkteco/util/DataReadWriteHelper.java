package com.zkteco.util;

import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author yuyi.liu
 *
 */
public class DataReadWriteHelper {

	/**
	 * 命令模式
	 * 
	 * @param fileName
	 * @param byteSize
	 * @param callback
	 * @return
	 * @throws IOException
	 */
	public static List<Object> readData(String fileName, int byteSize, DataHandleCallback callback) throws IOException {
		List<Object> list = new ArrayList<Object>();
		if (byteSize == 0) {
			return list;
		}
		File f = new File(fileName);
		if (!f.exists()) {
			throw new FileNotFoundException(fileName);
		}
		ByteArrayOutputStream bos = new ByteArrayOutputStream((int) f.length());
		BufferedInputStream in = null;
		try {
			in = new BufferedInputStream(new FileInputStream(f));
			byte[] buffer = new byte[byteSize];
			if (in.available() % byteSize == 0) {
				while (-1 != (in.read(buffer, 0, byteSize))) {
					Object bean = callback.doReadHandle(buffer);
					list.add(bean);
				}
			} else {
				throw new FileNotFoundException("文件已损坏");
			}
		} catch (IOException e) {
			e.printStackTrace();
			throw e;
		} finally {
			try {
				in.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			bos.close();
		}
		return list;
	}

	public static byte[] writeData(Object bean, DataHandleCallback callback) throws IOException {
		return callback.doWriteHandle(bean);
	}

}
