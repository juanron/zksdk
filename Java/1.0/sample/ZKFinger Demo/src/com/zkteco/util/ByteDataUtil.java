package com.zkteco.util;

import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

/**
 * @author yuyi.liu
 *
 */
public class ByteDataUtil {
	public static final String _Encoding = "UTF-8";
	public static final  SimpleDateFormat dateFormat=new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
	public static long changeByte(byte[] bytes){
		if (bytes.length>4) {
			throw new IndexOutOfBoundsException();
		}
		long res=0;
		for (int i = bytes.length-1;i >=0; i--) {
			res|=bytes[i]<<(i*8);
		}
		return res;
	}
	 
	public static long readShort(DataInputStream data) throws IOException{
		long changeByte = changeByte(readByte(data, 2));
		return changeByte;
	}
	 
	public static long readLong(DataInputStream data) throws IOException{
		byte[] bytes = readByte(data, 4);
		return(0xffL & (long)bytes[0]) | (0xff00L & ((long)bytes[1] << 8)) | (0xff0000L & ((long)bytes[2] << 16)) | (0xff000000L & ((long)bytes[3] << 24));
 
	}
	
	public static long[] readShort(DataInputStream data,int size) throws IOException{
		long[] shortDatas=new long[size];
		for (int i = 0; i < shortDatas.length; i++) {
			shortDatas[i]=readShort(data);
		}
		return shortDatas;
	}
	 
	public static long readBytetoLong(DataInputStream data) throws IOException{
		return data.readByte()&0xff;
	}
	public static long[] readBytetoLong(DataInputStream data,int size) throws IOException{
		long[] longDatas=new long[size];
		for (int i = 0; i < longDatas.length; i++) {
			longDatas[i]=data.readByte()&0xff;
		}
		return longDatas;
	}
	public static byte[] readByte(DataInputStream data,int size) throws IOException{
		byte[] byteData = new byte[size];
		data.read(byteData);
		return byteData;
	}
	public static String readString(DataInputStream data,int size) throws IOException{
		byte[] byteData = new byte[size];
		data.read(byteData);
		return new String(byteData, _Encoding).trim();
	}
	public static byte[] writeString2Byte(String s,int size){
		byte[] res=new byte[size];
		byte[] bytes = s.getBytes();
		if(bytes.length>size){
			throw new IndexOutOfBoundsException();
		}
		for (int i = 0; i < bytes.length; i++) {
			res[i]=bytes[i];
		}
		 
		return res;
	}
	public static byte[] writeLong2Byte(long[] l,int size) throws IOException{
		byte[] res=new byte[l.length*size];
		int i=0;
		for (long m : l) {
			byte[] writeLong2Byte = writeLong2Byte(m, size);
			for (byte b : writeLong2Byte) {
				res[i++]=b;
			}
		}
		return res;
	}
	public static byte[] writeDouble2Byte(Double d,int size) throws IOException{
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		ObjectOutputStream out=new ObjectOutputStream(baos);
		out.writeObject(d);
		byte[] byteArray = baos.toByteArray();
		  
		byte[]res=	new byte[size];
		switch (size) {
		case 1:
			res= new byte[]{byteArray[byteArray.length-1]};
			break;
		case 2:
			res= new byte[]{byteArray[byteArray.length-1],byteArray[byteArray.length-2]};
			break;
		case 3:
			res= new byte[]{byteArray[byteArray.length-1],byteArray[byteArray.length-2],byteArray[byteArray.length-3]};
			break;
		case 4:
			res= new byte[]{byteArray[byteArray.length-1],byteArray[byteArray.length-2],byteArray[byteArray.length-3],byteArray[byteArray.length-4]};
			break;
		}
	 
		return res;
	}
	public static byte[] writeLong2Byte(long l,int size) throws IOException{
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		ObjectOutputStream out=new ObjectOutputStream(baos);
		out.writeObject(l);
		byte[] byteArray = baos.toByteArray();
		  
		byte[]res=	new byte[size];
		switch (size) {
		case 1:
			res= new byte[]{byteArray[byteArray.length-1]};
			break;
		case 2:
			res= new byte[]{byteArray[byteArray.length-1],byteArray[byteArray.length-2]};
			break;
		case 3:
			res= new byte[]{byteArray[byteArray.length-1],byteArray[byteArray.length-2],byteArray[byteArray.length-3]};
			break;
		case 4:
			res= new byte[]{byteArray[byteArray.length-1],byteArray[byteArray.length-2],byteArray[byteArray.length-3],byteArray[byteArray.length-4]};
			break;
		}
		 
		return res;
	}
	 
    public static Date readDateTime(DataInputStream data) throws IOException
    {
    	int readInt = data.readUnsignedByte();
    	int readInt1 = data.readUnsignedByte();
    	int readInt2 = data.readUnsignedByte();
    	int readInt3 = data.readUnsignedByte();
        int[] timebytes =new int[]{readInt,readInt1,readInt2,readInt3};
        long Time=0;//482853600
        for (int i = 0; i < 4; i++)
        {
        	Time += timebytes[i] * Math.pow(16.0, 2.0 * i);
        } 
    	//482248800  515964300
        int Year, Month, Day, Hour, Minute, Second;
        Second = (int) (Time % 60);
        Time /= 60;
        Minute = (int) (Time % 60);
        Time /= 60;
        Hour = (int) (Time % 24);
        Time /= 24;
        Day = (int) (Time % 31 + 1);
        Time /= 31;
        Month = (int) (Time % 12) ;
        Time /= 12;
        Year = (int) (Time + 2000);
       // DateTime dt;
        Calendar time = Calendar.getInstance();
        time.set(Year, Month, Day, Hour, Minute, Second);
        
        /*System.out.println(dateFormat.format( time.getTime()));
        long timeInMillis = (time.getTime().getTime()/1000-937324800);
        System.out.println("515964300 ->"+timeInMillis);*/
        return  time.getTime();
    }

    public static byte[] writeDateTime(Date date,int size) throws  IOException
    {
    	
        long t =(long) ((((date.getYear()+1900) % 100) * 12 * 31 + (date.getMonth()  * 31) + date.getDate() - 1) * (24 * 60 * 60) +
            (date.getHours() * 60 + date.getMinutes()) * 60 + date.getSeconds());
       return  writeLong2Byte(t, size);
    }
}
