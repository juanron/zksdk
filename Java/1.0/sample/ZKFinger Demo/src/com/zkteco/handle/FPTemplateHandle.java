package com.zkteco.handle;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

import com.zkteco.bean.FPTemplateBean;
import com.zkteco.util.ByteDataUtil;
import com.zkteco.util.DataHandleCallback;
import com.zkteco.util.DataReadWriteHelper;

public class FPTemplateHandle implements DataHandleCallback {

	@Override
	public Object doReadHandle(byte[] bytes) throws IOException {
		DataInputStream data = new DataInputStream(new ByteArrayInputStream(bytes));
		FPTemplateBean template = new FPTemplateBean();
		template.setSize(ByteDataUtil.readShort(data));
		template.setUserId(ByteDataUtil.readString(data, 24));
		template.setFingerID(ByteDataUtil.readBytetoLong(data));
		template.setValid(ByteDataUtil.readBytetoLong(data));
		template.setTemplate(ByteDataUtil.readString(data, 3096));
		System.out.println(template);
		return template;
	}

	@Override
	public byte[] doWriteHandle(Object bean) throws IOException {
		if (bean != null) {
			System.out.println("------------------------------------");
			System.out.println(bean);
			ByteArrayOutputStream out = new ByteArrayOutputStream();
			DataOutputStream data = new DataOutputStream(out);
			FPTemplateBean template = (FPTemplateBean) bean;
			data.write(ByteDataUtil.writeLong2Byte(template.getSize(), 2));
			data.write(ByteDataUtil.writeString2Byte(template.getUserId(), 24));
			data.write(ByteDataUtil.writeLong2Byte(template.getFingerID(), 1));
			data.write(ByteDataUtil.writeLong2Byte(template.getValid(), 1));
			data.write(ByteDataUtil.writeString2Byte(template.getTemplate(), 3096));
			return out.toByteArray();
		}
		return null;
	}

	public static void main(String[] args) throws IOException {
		FPTemplateHandle templateHandle = new FPTemplateHandle();
		String fileName = "D:/workspace/ZKPushSDK/data/zktemplate[10.0].dat";
		List<Object> readData = DataReadWriteHelper.readData(fileName, 3124, templateHandle);

		System.out.println("====================================");
		String fileName2 = "D:/workspace/ZKPushSDK/data/zktemplate[10.0]_test.dat";

		FileOutputStream outputStream = new FileOutputStream(fileName2);
		for (Object object : readData) {
			byte[] writeData = DataReadWriteHelper.writeData(object, templateHandle);
			outputStream.write(writeData);
			outputStream.flush();
		}
		outputStream.close();
	}
}
