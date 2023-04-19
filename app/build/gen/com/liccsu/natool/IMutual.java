/*
 * This file is auto-generated.  DO NOT MODIFY.
 * Original file: /storage/emulated/0/AppProjects/王者jni源码/app/src/main/aidl/com/liccsu/natool/IMutual.aidl
 */
package com.liccsu.natool;
// Declare any non-default types here with import statements

public interface IMutual extends android.os.IInterface
{
/** Local-side IPC implementation stub class. */
public static abstract class Stub extends android.os.Binder implements com.liccsu.natool.IMutual
{
private static final java.lang.String DESCRIPTOR = "com.liccsu.natool.IMutual";
/** Construct the stub at attach it to the interface. */
public Stub()
{
this.attachInterface(this, DESCRIPTOR);
}
/**
 * Cast an IBinder object into an com.liccsu.natool.IMutual interface,
 * generating a proxy if needed.
 */
public static com.liccsu.natool.IMutual asInterface(android.os.IBinder obj)
{
if ((obj==null)) {
return null;
}
android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
if (((iin!=null)&&(iin instanceof com.liccsu.natool.IMutual))) {
return ((com.liccsu.natool.IMutual)iin);
}
return new com.liccsu.natool.IMutual.Stub.Proxy(obj);
}
@Override public android.os.IBinder asBinder()
{
return this;
}
@Override public boolean onTransact(int code, android.os.Parcel data, android.os.Parcel reply, int flags) throws android.os.RemoteException
{
java.lang.String descriptor = DESCRIPTOR;
switch (code)
{
case INTERFACE_TRANSACTION:
{
reply.writeString(descriptor);
return true;
}
case TRANSACTION_setSurface_Surface:
{
data.enforceInterface(descriptor);
android.view.Surface _arg0;
if ((0!=data.readInt())) {
_arg0 = android.view.Surface.CREATOR.createFromParcel(data);
}
else {
_arg0 = null;
}
this.setSurface(_arg0);
reply.writeNoException();
return true;
}
case TRANSACTION_navateInputEvent_MotionEvent:
{
data.enforceInterface(descriptor);
android.view.MotionEvent _arg0;
if ((0!=data.readInt())) {
_arg0 = android.view.MotionEvent.CREATOR.createFromParcel(data);
}
else {
_arg0 = null;
}
this.navateInputEvent(_arg0);
reply.writeNoException();
return true;
}
case TRANSACTION_getMenuW:
{
data.enforceInterface(descriptor);
float _result = this.getMenuW();
reply.writeNoException();
reply.writeFloat(_result);
return true;
}
case TRANSACTION_getMenuH:
{
data.enforceInterface(descriptor);
float _result = this.getMenuH();
reply.writeNoException();
reply.writeFloat(_result);
return true;
}
case TRANSACTION_getMenuX:
{
data.enforceInterface(descriptor);
float _result = this.getMenuX();
reply.writeNoException();
reply.writeFloat(_result);
return true;
}
case TRANSACTION_getMenuY:
{
data.enforceInterface(descriptor);
float _result = this.getMenuY();
reply.writeNoException();
reply.writeFloat(_result);
return true;
}
case TRANSACTION_setPid_int:
{
data.enforceInterface(descriptor);
int _arg0;
_arg0 = data.readInt();
this.setPid(_arg0);
reply.writeNoException();
return true;
}
case TRANSACTION_getPID_String:
{
data.enforceInterface(descriptor);
java.lang.String _arg0;
_arg0 = data.readString();
int _result = this.getPID(_arg0);
reply.writeNoException();
reply.writeInt(_result);
return true;
}
default:
{
return super.onTransact(code, data, reply, flags);
}
}
}
private static class Proxy implements com.liccsu.natool.IMutual
{
private android.os.IBinder mRemote;
Proxy(android.os.IBinder remote)
{
mRemote = remote;
}
@Override public android.os.IBinder asBinder()
{
return mRemote;
}
public java.lang.String getInterfaceDescriptor()
{
return DESCRIPTOR;
}
@Override public void setSurface(android.view.Surface surface) throws android.os.RemoteException
{
android.os.Parcel _data = android.os.Parcel.obtain();
android.os.Parcel _reply = android.os.Parcel.obtain();
try {
_data.writeInterfaceToken(DESCRIPTOR);
if ((surface!=null)) {
_data.writeInt(1);
surface.writeToParcel(_data, 0);
}
else {
_data.writeInt(0);
}
mRemote.transact(Stub.TRANSACTION_setSurface_Surface, _data, _reply, 0);
_reply.readException();
}
finally {
_reply.recycle();
_data.recycle();
}
}
@Override public void navateInputEvent(android.view.MotionEvent motionEvent) throws android.os.RemoteException
{
android.os.Parcel _data = android.os.Parcel.obtain();
android.os.Parcel _reply = android.os.Parcel.obtain();
try {
_data.writeInterfaceToken(DESCRIPTOR);
if ((motionEvent!=null)) {
_data.writeInt(1);
motionEvent.writeToParcel(_data, 0);
}
else {
_data.writeInt(0);
}
mRemote.transact(Stub.TRANSACTION_navateInputEvent_MotionEvent, _data, _reply, 0);
_reply.readException();
}
finally {
_reply.recycle();
_data.recycle();
}
}
@Override public float getMenuW() throws android.os.RemoteException
{
android.os.Parcel _data = android.os.Parcel.obtain();
android.os.Parcel _reply = android.os.Parcel.obtain();
float _result;
try {
_data.writeInterfaceToken(DESCRIPTOR);
mRemote.transact(Stub.TRANSACTION_getMenuW, _data, _reply, 0);
_reply.readException();
_result = _reply.readFloat();
}
finally {
_reply.recycle();
_data.recycle();
}
return _result;
}
@Override public float getMenuH() throws android.os.RemoteException
{
android.os.Parcel _data = android.os.Parcel.obtain();
android.os.Parcel _reply = android.os.Parcel.obtain();
float _result;
try {
_data.writeInterfaceToken(DESCRIPTOR);
mRemote.transact(Stub.TRANSACTION_getMenuH, _data, _reply, 0);
_reply.readException();
_result = _reply.readFloat();
}
finally {
_reply.recycle();
_data.recycle();
}
return _result;
}
@Override public float getMenuX() throws android.os.RemoteException
{
android.os.Parcel _data = android.os.Parcel.obtain();
android.os.Parcel _reply = android.os.Parcel.obtain();
float _result;
try {
_data.writeInterfaceToken(DESCRIPTOR);
mRemote.transact(Stub.TRANSACTION_getMenuX, _data, _reply, 0);
_reply.readException();
_result = _reply.readFloat();
}
finally {
_reply.recycle();
_data.recycle();
}
return _result;
}
@Override public float getMenuY() throws android.os.RemoteException
{
android.os.Parcel _data = android.os.Parcel.obtain();
android.os.Parcel _reply = android.os.Parcel.obtain();
float _result;
try {
_data.writeInterfaceToken(DESCRIPTOR);
mRemote.transact(Stub.TRANSACTION_getMenuY, _data, _reply, 0);
_reply.readException();
_result = _reply.readFloat();
}
finally {
_reply.recycle();
_data.recycle();
}
return _result;
}
@Override public void setPid(int pid) throws android.os.RemoteException
{
android.os.Parcel _data = android.os.Parcel.obtain();
android.os.Parcel _reply = android.os.Parcel.obtain();
try {
_data.writeInterfaceToken(DESCRIPTOR);
_data.writeInt(pid);
mRemote.transact(Stub.TRANSACTION_setPid_int, _data, _reply, 0);
_reply.readException();
}
finally {
_reply.recycle();
_data.recycle();
}
}
@Override public int getPID(java.lang.String packageName) throws android.os.RemoteException
{
android.os.Parcel _data = android.os.Parcel.obtain();
android.os.Parcel _reply = android.os.Parcel.obtain();
int _result;
try {
_data.writeInterfaceToken(DESCRIPTOR);
_data.writeString(packageName);
mRemote.transact(Stub.TRANSACTION_getPID_String, _data, _reply, 0);
_reply.readException();
_result = _reply.readInt();
}
finally {
_reply.recycle();
_data.recycle();
}
return _result;
}
}
static final int TRANSACTION_setSurface_Surface = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
static final int TRANSACTION_navateInputEvent_MotionEvent = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
static final int TRANSACTION_getMenuW = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
static final int TRANSACTION_getMenuH = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
static final int TRANSACTION_getMenuX = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
static final int TRANSACTION_getMenuY = (android.os.IBinder.FIRST_CALL_TRANSACTION + 5);
static final int TRANSACTION_setPid_int = (android.os.IBinder.FIRST_CALL_TRANSACTION + 6);
static final int TRANSACTION_getPID_String = (android.os.IBinder.FIRST_CALL_TRANSACTION + 7);
}
public void setSurface(android.view.Surface surface) throws android.os.RemoteException;
public void navateInputEvent(android.view.MotionEvent motionEvent) throws android.os.RemoteException;
public float getMenuW() throws android.os.RemoteException;
public float getMenuH() throws android.os.RemoteException;
public float getMenuX() throws android.os.RemoteException;
public float getMenuY() throws android.os.RemoteException;
public void setPid(int pid) throws android.os.RemoteException;
public int getPID(java.lang.String packageName) throws android.os.RemoteException;
}
