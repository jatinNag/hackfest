import 'package:flutter/material.dart';
import 'package:flutter_app/DataModel/Permission.dart';
import 'package:flutter_app/constants/constants.dart';
class MyHomePage extends StatefulWidget {
  MyHomePage({Key key, this.title}) : super(key: key);



  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;

  List<Widget> permissionsWidgetList = List.empty(growable: true);
  @override
  void initState() {
    // TODO: implement initState
    super.initState();
//    permissionsWidgetList =  getPermissionStatus();
  }


  @override
  Widget build(BuildContext context) {

    return Scaffold(
      appBar: AppBar(

        title: Text(widget.title),
      ),
      body: Center(

        child: FutureBuilder(
          future: getPermissionStatus(),

          builder: (BuildContext context,AsyncSnapshot<List<Widget>> snapshot){
            if(snapshot.hasData){
                return         Column(

          mainAxisAlignment: MainAxisAlignment.center,
          children: snapshot.data
//              <Widget>[
//            Text(
//              'You have pushed the button this many times:',
//            ),
//            Text(
//              '$_counter',
//              style: Theme.of(context).textTheme.headline4,
//            ),
//          ],
        );
            }else{
              return Text("requesting permissions");
            }
        },
        )


      ),

    );
  }
  Future<List<Widget>> getPermissionStatus()async{
    List<Widget> permissionWidget  = List.empty(growable: true);
    List<bool> permissionStatus = await Permissions().getPermission();
    print(Constants.permissionsName.length);
    for(int i = 0;i<Constants.permissionsName.length;i++){
      print(permissionStatus[i]);
      Widget permission = Row(
        children: [
          permissionStatus[i]?Image.asset("assets/check.jpg"):Image.asset("assets/x.jpg"),
          Text(Constants.permissionsName[i]),
        ],
      );
      permissionWidget.add(permission);
    }
    return permissionWidget;

  }


}
