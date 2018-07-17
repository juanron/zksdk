package com.zkteco.biometric;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;

import sun.misc.BASE64Encoder;

import com.sun.org.apache.xml.internal.security.utils.Base64;
import com.zkteco.bean.FPTemplateBean;
import com.zkteco.handle.FPTemplateHandle;
import com.zkteco.util.DataReadWriteHelper;

public class ZKFPDemo extends JFrame{
	JButton btnBegin = null;
	JButton btnEnroll = null;
	JButton btnVerify = null;
	JButton btnIdentify = null;
	JButton btnRegImg = null;
	JButton btnIdentImg = null;
	JButton btnEnd = null;
	JButton btnImg = null;
	private JTextArea textArea;
	
	//the width of fingerprint image
	int width = 0;
	//the height of fingerprint image
	int height = 0;
	//for verify test
	private byte[] lastRegTemp = new byte[2048];
	//the length of lastRegTemp
	private int cbRegTemp = 0;
	//pre-register template
	private byte[][] regtemparray = new byte[3][2048];
	//Register
	private boolean bRegister = false;
	//Identify
	private boolean bIdentify = true;
	//finger id
	private int iFid = 1;
	//must be 3
	static final int enroll_cnt = 3;
	//the index of pre-register function
	private int enroll_idx = 0;
	//fingerprintsensor
	FingerprintSensor fingerprintSensor = null;
	public void launchFrame(){
		this.setLayout (null);
		btnBegin = new JButton("Begin");  
		this.add(btnBegin);  
		int nRsize = 30;
		btnBegin.setBounds(30, 10 + nRsize, 100, 30);
		
		btnEnroll = new JButton("Enroll");  
		this.add(btnEnroll);  
		btnEnroll.setBounds(30, 70 + nRsize, 100, 30);
		
		btnVerify = new JButton("Verify");  
		this.add(btnVerify);  
		btnVerify.setBounds(30, 130 + nRsize, 100, 30);
		
		btnIdentify = new JButton("Identify");  
		this.add(btnIdentify);  
		btnIdentify.setBounds(30, 190 + nRsize, 100, 30);
		
		btnRegImg = new JButton("Register By Image");  
		this.add(btnRegImg);  
		btnRegImg.setBounds(15, 250 + nRsize, 120, 30);
		
		btnIdentImg = new JButton("Verify By Image");  
		this.add(btnIdentImg);  
		btnIdentImg.setBounds(15, 310 + nRsize, 120, 30);
		
		
		btnEnd = new JButton("Stop");  
		this.add(btnEnd);  
		btnEnd.setBounds(30, 370 + nRsize, 100, 30);
		
		btnImg = new JButton();
		btnImg.setBounds(150, 5, 256, 300);
		btnImg.setDefaultCapable(false);
		this.add(btnImg); 
		
		textArea = new JTextArea();
		this.add(textArea);  
		textArea.setBounds(10, 440, 480, 100);
		
		
		this.setSize(520, 580);
		this.setLocationRelativeTo(null);
		this.setVisible(true);
		this.setTitle("ZKFinger Demo");
		this.setResizable(false);
		
		btnBegin.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if (fingerprintSensor != null)
				{
					textArea.setText("Sensor was already opened!");
					return;
				}
				//Initialize
				cbRegTemp = 0;
				bRegister = false;
				bIdentify = false;
				iFid = 1;
				enroll_idx = 0;
				fingerprintSensor = new FingerprintSensor();
				int ret = fingerprintSensor.getDeviceCount();
				if (ret < 0)
				{
					textArea.setText("No devices connected!");
					FreeSensor();
					return;
				}
				if (FingerprintSensorErrorCode.ERROR_SUCCESS != (ret = fingerprintSensor.openDevice(0)))
				{
					textArea.setText("Open device fail, ret = " + ret + "!");
					FreeSensor();
					return;
				}
				fingerprintSensor.setFakeFunOn(1);
				width = fingerprintSensor.getImageWidth();
				height = fingerprintSensor.getImageHeight();
				btnImg.resize(width, height);
				final FingerprintCaptureListener listener = new FingerprintCaptureListener() {
					@Override
					public void captureError(int arg0) {
						// TODO Auto-generated method stub
						//textArea.setText("captureError! error code = " + arg0);
					}
					@Override
					public void captureOK(byte[] arg0) {
						// TODO Auto-generated method stub
						//textArea.setText("captureOK!\r\n" + textArea.getText());
						try {
							writeBitmap(arg0, width, height, "fingerprint.bmp");
							btnImg.setIcon(new ImageIcon(ImageIO.read(new File("fingerprint.bmp"))));
						} catch (IOException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
					@Override
					public void extractOK(byte[] arg0) {
						// TODO Auto-generated method stub
						//textArea.setText("extractOK!\r\n" + textArea.getText());
						if (fingerprintSensor.getFakeFunOn() == 1)
						{
							int fakeStatus = fingerprintSensor.getFakeStatus();
							if ((fakeStatus & 31) != 31)
							{
								textArea.setText("Is Fake Finger！ ");
								return;
							}
						}
						if(bRegister)
						{
							int[] fid = new int[1];
							int[] score = new int [1];
                            int ret = fingerprintSensor.IdentifyFP(arg0, fid, score);
                            if (ret == 0)
                            {
                                textArea.setText("the finger already enroll by " + fid[0] + ",cancel enroll");
                                bRegister = false;
                                enroll_idx = 0;
                                return;
                            }
                            if (enroll_idx > 0 && fingerprintSensor.MatchFP(regtemparray[enroll_idx-1], arg0) <= 0)
                            {
                            	textArea.setText("please press the same finger 3 times for the enrollment");
                                return;
                            }
                            System.arraycopy(arg0, 0, regtemparray[enroll_idx], 0, 2048);
                            enroll_idx++;
                            if (enroll_idx == 3) {
                            	int[] _retLen = new int[1];
                                _retLen[0] = 2048;
                                byte[] regTemp = new byte[_retLen[0]];
                                
                                if (0 == (ret = fingerprintSensor.GenRegFPTemplate(regtemparray[0], regtemparray[1], regtemparray[2], regTemp, _retLen)) &&
                                		0 == (ret = fingerprintSensor.DBAdd(iFid, regTemp))) {
                                	iFid++;
                                	cbRegTemp = _retLen[0];
                                    System.arraycopy(regTemp, 0, lastRegTemp, 0, cbRegTemp);
                                    //Base64 Template
                                    textArea.setText("enroll succ");
                                } else {
                                	textArea.setText("enroll fail, error code=" + ret);
                                }
                                bRegister = false;
                            } else {
                            	textArea.setText("You need to press the " + (3 - enroll_idx) + " times fingerprint");
                            }
						}
						else
						{
							if (bIdentify)
							{
								int[] fid = new int[1];
								int[] score = new int [1];
								int ret = fingerprintSensor.IdentifyFP(arg0, fid, score);
		                        if (ret == 0)
		                        {
		                        	textArea.setText("Identify succ, fid=" + fid[0] + ",score=" + score[0]);
		                        }
		                        else
		                        {
		                        	textArea.setText("Identify fail, errcode=" + ret);
		                        }
	                                
							}
							else
							{
								if(cbRegTemp <= 0)
								{
									textArea.setText("Please register first!");
								}
								else
								{
									int ret = fingerprintSensor.MatchFP(lastRegTemp, arg0);
									if(ret > 0)
									{
										textArea.setText("Verify succ, score=" + ret);
									}
									else
									{
										textArea.setText("Verify fail, ret=" + ret);
									}
								}
							}
						}
					}
	            }; 
	            fingerprintSensor.setFingerprintCaptureListener(listener);
	            if (!fingerprintSensor.startCapture())
	            {
	            	FreeSensor();
	            	textArea.setText("startCapture fail!");
					return;
	            }
	            textArea.setText("start succ!");
			}
		});
		
		
		
		btnEnd.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				FreeSensor();
				
				textArea.setText("stop succ!");
			}
		});
		
		btnEnroll.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				if(null == fingerprintSensor)
				{
					textArea.setText("Please begin capture first!");
					return;
				}
				if(!bRegister)
				{
					enroll_idx = 0;
					bRegister = true;
					textArea.setText("Please your finger 3 times!");
				}
			}
			});
		
		btnVerify.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				if(null == fingerprintSensor)
				{
					textArea.setText("Please begin capture first!");
					return;
				}
				if(bRegister)
				{
					enroll_idx = 0;
					bRegister = false;
				}
				if(bIdentify)
				{
					bIdentify = false;
				}
			}
			});
		
		btnIdentify.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				if(null == fingerprintSensor)
				{
					textArea.setText("Please begin capture first!");
					return;
				}
				if(bRegister)
				{
					enroll_idx = 0;
					bRegister = false;
				}
				if(!bIdentify)
				{
					bIdentify = true;
				}
			}
			});
		
		
		btnRegImg.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				if(null == fingerprintSensor)
				{
					textArea.setText("Please begin capture first!");
				}
				String path = "d:\\test\\fingerprint.bmp";
				byte[] fpTemplate = new byte[2048];
				int[] sizeFPTemp = new int[1];
				sizeFPTemp[0] = 2048;
				int ret = fingerprintSensor.ExtractFromImage(path, 500, fpTemplate, sizeFPTemp);
				if (0 == ret)
				{
					ret = fingerprintSensor.DBAdd(iFid, fpTemplate);
					if (0 == ret)
					{
						String base64 = fingerprintSensor.BlobToBase64(fpTemplate, sizeFPTemp[0]);
						//For Push SDK Begin
						setTemplateToFile(base64, "123", 0, 1, "D:/test/zktemplate[10.0]_test.dat");
						//For Push SDK End
						iFid++;
                    	cbRegTemp = sizeFPTemp[0];
                        System.arraycopy(fpTemplate, 0, lastRegTemp, 0, cbRegTemp);
                        //Base64 Template
                        //String strBase64 = Base64.encodeToString(regTemp, 0, ret, Base64.NO_WRAP);
                        textArea.setText("enroll succ");
					}
					else
					{
						textArea.setText("DBAdd fail, ret=" + ret);
					}
				}
				else
				{
					textArea.setText("ExtractFromImage fail, ret=" + ret);
				}
			}
			});
		
		
		btnIdentImg.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				if(null == fingerprintSensor)
				{
					textArea.setText("Please begin capture first!");
				}
				String path = "d:\\test\\fingerprint.bmp";
				byte[] fpTemplate = new byte[2048];
				int[] sizeFPTemp = new int[1];
				sizeFPTemp[0] = 2048;
				int ret = fingerprintSensor.ExtractFromImage(path, 500, fpTemplate, sizeFPTemp);
				if (0 == ret)
				{
					if (bIdentify)
					{
						int[] fid = new int[1];
						int[] score = new int [1];
						ret = fingerprintSensor.IdentifyFP(fpTemplate, fid, score);
                        if (ret == 0)
                        {
                        	textArea.setText("Identify succ, fid=" + fid[0] + ",score=" + score[0]);
                        }
                        else
                        {
                        	textArea.setText("Identify fail, errcode=" + ret);
                        }
                            
					}
					else
					{
						if(cbRegTemp <= 0)
						{
							textArea.setText("Please register first!");
						}
						else
						{
							ret = fingerprintSensor.MatchFP(lastRegTemp, fpTemplate);
							if(ret > 0)
							{
								textArea.setText("Verify succ, score=" + ret);
							}
							else
							{
								textArea.setText("Verify fail, ret=" + ret);
							}
						}
					}
				}
				else
				{
					textArea.setText("ExtractFromImage fail, ret=" + ret);
				}
			}
		});
	
		
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.addWindowListener(new WindowAdapter(){

            @Override
            public void windowClosing(WindowEvent e) {
                // TODO Auto-generated method stub
            	FreeSensor();
            }
		});
	}

	//For Push SDK
	private void setTemplateToFile(String temp, String uid, int fid, int valid, String filePath)
	{
		FPTemplateBean fpTemplateBean = new FPTemplateBean();
		fpTemplateBean.setFingerID(fid);
		fpTemplateBean.setSize(temp.length());
		fpTemplateBean.setTemplate(temp);
		fpTemplateBean.setUserId(uid);
		fpTemplateBean.setValid(valid);
		
		FPTemplateHandle templateHandle = new FPTemplateHandle();
		FileOutputStream outputStream = null;
		byte[] writeData = null;
		try {
			outputStream = new FileOutputStream(filePath);
			if (null != outputStream)
			{
				writeData = templateHandle.doWriteHandle(fpTemplateBean);
				if (null != writeData)
				{
					outputStream.write(writeData);
					outputStream.flush();
				}
				outputStream.close();
			}
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	}
	
	private void FreeSensor()
	{
		if (null != fingerprintSensor)
		{
			fingerprintSensor.stopCapture();
			fingerprintSensor.closeDevice();
			fingerprintSensor.destroy();
			fingerprintSensor = null;
		}
	}
	
	public static void writeBitmap(byte[] imageBuf, int nWidth, int nHeight,
			String path) throws IOException {
		java.io.FileOutputStream fos = new java.io.FileOutputStream(path);
		java.io.DataOutputStream dos = new java.io.DataOutputStream(fos);

		int bfType = 0x424d; // 位图文件类型（0—1字节）
		int bfSize = 54 + 1024 + nWidth * nHeight;// bmp文件的大小（2—5字节）
		int bfReserved1 = 0;// 位图文件保留字，必须为0（6-7字节）
		int bfReserved2 = 0;// 位图文件保留字，必须为0（8-9字节）
		int bfOffBits = 54 + 1024;// 文件头开始到位图实际数据之间的字节的偏移量（10-13字节）

		dos.writeShort(bfType); // 输入位图文件类型'BM'
		dos.write(changeByte(bfSize), 0, 4); // 输入位图文件大小
		dos.write(changeByte(bfReserved1), 0, 2);// 输入位图文件保留字
		dos.write(changeByte(bfReserved2), 0, 2);// 输入位图文件保留字
		dos.write(changeByte(bfOffBits), 0, 4);// 输入位图文件偏移量

		int biSize = 40;// 信息头所需的字节数（14-17字节）
		int biWidth = nWidth;// 位图的宽（18-21字节）
		int biHeight = nHeight;// 位图的高（22-25字节）
		int biPlanes = 1; // 目标设备的级别，必须是1（26-27字节）
		int biBitcount = 8;// 每个像素所需的位数（28-29字节），必须是1位（双色）、4位（16色）、8位（256色）或者24位（真彩色）之一。
		int biCompression = 0;// 位图压缩类型，必须是0（不压缩）（30-33字节）、1（BI_RLEB压缩类型）或2（BI_RLE4压缩类型）之一。
		int biSizeImage = nWidth * nHeight;// 实际位图图像的大小，即整个实际绘制的图像大小（34-37字节）
		int biXPelsPerMeter = 0;// 位图水平分辨率，每米像素数（38-41字节）这个数是系统默认值
		int biYPelsPerMeter = 0;// 位图垂直分辨率，每米像素数（42-45字节）这个数是系统默认值
		int biClrUsed = 0;// 位图实际使用的颜色表中的颜色数（46-49字节），如果为0的话，说明全部使用了
		int biClrImportant = 0;// 位图显示过程中重要的颜色数(50-53字节)，如果为0的话，说明全部重要

		dos.write(changeByte(biSize), 0, 4);// 输入信息头数据的总字节数
		dos.write(changeByte(biWidth), 0, 4);// 输入位图的宽
		dos.write(changeByte(biHeight), 0, 4);// 输入位图的高
		dos.write(changeByte(biPlanes), 0, 2);// 输入位图的目标设备级别
		dos.write(changeByte(biBitcount), 0, 2);// 输入每个像素占据的字节数
		dos.write(changeByte(biCompression), 0, 4);// 输入位图的压缩类型
		dos.write(changeByte(biSizeImage), 0, 4);// 输入位图的实际大小
		dos.write(changeByte(biXPelsPerMeter), 0, 4);// 输入位图的水平分辨率
		dos.write(changeByte(biYPelsPerMeter), 0, 4);// 输入位图的垂直分辨率
		dos.write(changeByte(biClrUsed), 0, 4);// 输入位图使用的总颜色数
		dos.write(changeByte(biClrImportant), 0, 4);// 输入位图使用过程中重要的颜色数

		for (int i = 0; i < 256; i++) {
			dos.writeByte(i);
			dos.writeByte(i);
			dos.writeByte(i);
			dos.writeByte(0);
		}

		for(int i=0;i<nHeight;i++)
			dos.write(imageBuf, (nHeight-1-i)*nWidth, nWidth);
		dos.flush();
		dos.close();
		fos.close();
	}

	public static byte[] changeByte(int data) {
		byte b4 = (byte) ((data) >> 24);
		byte b3 = (byte) (((data) << 8) >> 24);
		byte b2 = (byte) (((data) << 16) >> 24);
		byte b1 = (byte) (((data) << 24) >> 24);
		byte[] bytes = { b1, b2, b3, b4 };
		return bytes;
	}
		
		public static void main(String[] args) {
			new ZKFPDemo().launchFrame();
		}
}
