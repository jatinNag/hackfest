import 'package:flutter_app/constants/constants.dart';
import 'package:flutter_app/permission_layer/PermissionRequest.dart';
//["File System","Camera","Location","Bluetooth","SMS","Voice Input", "Notifications"]
class Permissions{
  Future<List<bool>> getPermission()async{
    List<bool> permissions = List.empty(growable: true);
    for(int i =0;i<Constants.permissionsName.length;i++){
      String permissionName = Constants.permissionsName[i];
      if(permissionName.toLowerCase()=="camera"){
        permissions.add(await RequestPermissions().getCameraPermissions());
       continue;
      }
      if(permissionName.toLowerCase()=="file system"){
//        permissions.add(true);
        permissions.add(await RequestPermissions().getFileSystemPermissions());
        continue;
      }
      if(permissionName.toLowerCase()=="location"){
        permissions.add(await RequestPermissions().getLocationPermissions());
        continue;
      }
      if(permissionName.toLowerCase()=="bluetooth"){
        permissions.add(await RequestPermissions().getBluetoothPermissions());
        continue;
      }
      if(permissionName.toLowerCase()=="sms"){
        permissions.add(await RequestPermissions().getSMSPermissions());
        continue;
      }
      if(permissionName.toLowerCase()=="voice input"){
        permissions.add(await RequestPermissions().getMicroPhonePermissions());
        continue;
      }
      if(permissionName.toLowerCase()=="notifications"){
        permissions.add(await RequestPermissions().getNotificationPermissions());
        continue;
      }
      print("issue");
      permissions.add(false);
    }
    return permissions;

  }

}
