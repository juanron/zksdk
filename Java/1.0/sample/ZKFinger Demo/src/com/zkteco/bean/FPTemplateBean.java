package com.zkteco.bean;

import java.util.Arrays;

/**
 * @author yuyi.liu
 *
 */
//fingerprint templates information of 10.0 arithmetic(Variable-length data format)
//The max length of one template is 16 kb, that is, one template's length is less than 16kb.
//The following is the fixed-length part of the data struct which is 6 bytes long.
//3124
public class FPTemplateBean {
	private long size;//2bit
	private String userId; // 24bit
	private long fingerID;//1
	private long valid;//1
	private String template; // 3096bit
	public long getSize() {
		return size;
	}
	public void setSize(long size) {
		this.size = size;
	}
	public String getUserId() {
		return userId;
	}
	public void setUserId(String userId) {
		this.userId = userId;
	}
	public long getFingerID() {
		return fingerID;
	}
	public void setFingerID(long fingerID) {
		this.fingerID = fingerID;
	}
	public long getValid() {
		return valid;
	}
	public void setValid(long valid) {
		this.valid = valid;
	}
	public String getTemplate() {
		return template;
	}
	public void setTemplate(String template) {
		this.template = template;
	}
	@Override
	public String toString() {
		return "FPTemplate [size=" + size + ", userId=" + userId + ", fingerID=" + fingerID + ", valid=" + valid
				+ ", template=" + template + "]";
	}
 
 
}
