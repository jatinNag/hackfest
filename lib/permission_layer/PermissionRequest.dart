

import 'package:permission_handler/permission_handler.dart';

class RequestPermissions{
  Future<bool> getCameraPermissions() async{
//    bool allowed = true;
    var status =await Permission.camera.status;
    if(status.isDenied){
      status = await Permission.camera.request();
      return status.isGranted;
    }else{
      return status.isGranted;
    }
//    return allowed;
  }
  Future<bool> getFileSystemPermissions() async{
    var status =await Permission.storage.status;
    if(status.isDenied){
      status = await Permission.storage.request();
      return status.isGranted;
    }else{
      return status.isGranted;
    }

  }
  Future<bool> getBluetoothPermissions()async{
return true;

  }
  Future<bool> getNotificationPermissions()async{
    var status =await Permission.notification.status;
    if(status.isDenied){
      status = await Permission.notification.request();
      return status.isGranted;
    }else{
      return status.isGranted;
    }

  }
  Future<bool> getLocationPermissions()async{
    var status =await Permission.location.status;
    if(status.isDenied){
      status = await Permission.location.request();
      return status.isGranted;
    }else{
      return status.isGranted;
    }
  }
  Future<bool> getSMSPermissions()async{
    var status =await Permission.sms.status;
    if(status.isDenied){
      status = await Permission.sms.request();
      return status.isGranted;
    }else{
      return status.isGranted;
    }
  }
  Future<bool> getMicroPhonePermissions()async{
    var status =await Permission.speech.status;
    if(status.isDenied){
      status = await Permission.speech.request();
      return status.isGranted;
    }else{
      return status.isGranted;
    }
  }
}