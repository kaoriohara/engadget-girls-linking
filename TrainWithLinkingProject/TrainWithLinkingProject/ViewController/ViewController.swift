//
//  ViewController.swift
//  TrainWithLinkingProject
//
//  Created by Aimi Kasama on 2016/03/13.
//  Copyright © 2016年 LinkingTeam1. All rights reserved.
//

import UIKit

class ViewController: UIViewController ,BLEConnecterDelegate{
    
    var connecter:BLEConnecter?
    var device:BLEDeviceSetting?
    var peripheral:CBPeripheral?
    var canLighting:Bool?

    @IBOutlet weak var searchButton: UIButton!
    @IBOutlet weak var connectButton: UIButton!
    @IBOutlet weak var lightButton: UIButton!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        connecter = BLEConnecter.sharedInstance()
        connecter?.addListener(self, deviceUUID: nil)
        connectButton.enabled = false;
        lightButton.enabled = false;
        
        //現在時刻
        let nowFormatter = NSDateFormatter()
        nowFormatter.dateFormat = "HH:mm"
        let nowTime = nowFormatter.stringFromDate(NSDate())
        print("現在時刻")
        print(nowTime)

        getTrainTime()
//        getPrefecture()
        
   }
    
    func getPrefecture(){
        let prefectureUrl:NSURL = NSURL(string: "http://geoapi.heartrails.com/api/xml?method=getPrefectures")!
        let prefectureJsonData = NSData(contentsOfURL: prefectureUrl)!
        do{
            let json = try NSJSONSerialization.JSONObjectWithData(prefectureJsonData, options: NSJSONReadingOptions.MutableContainers) as! NSArray
            let dict = json.objectAtIndex(0)
        }catch{
            
        }
    }
    
    func getTrainTime(){
        //時刻表
        print("時刻表")
        let timeArray:NSMutableArray = [];
        let url:NSURL = NSURL(string: "https://api.tokyometroapp.jp/api/v2/datapoints?rdf:type=odpt:StationTimetable&owl:sameAs=odpt.StationTimetable:TokyoMetro.Namboku.AkabaneIwabuchi&acl:consumerKey=b31ff347108b7a7b4682c4fb5379da5e45a794498be058c943930076dd492a23")!
        let jsonData = NSData(contentsOfURL: url)!
        do {
            let json = try NSJSONSerialization.JSONObjectWithData(jsonData, options: NSJSONReadingOptions.MutableContainers) as! NSArray
            let dict = json.objectAtIndex(0).objectForKey("odpt:saturdays") as! NSArray
            var timeCount = dict.count
            timeCount -= 1
            for i in 0...timeCount{
                let time = dict.objectAtIndex(i).objectForKey("odpt:departureTime") as! String
                timeArray.addObject(time)
            }
        }catch{
            
        }
        
        //時刻表の取得
        print(timeArray);

    }
    
    func canDiscoverDevice()->Bool{
        return (self.connecter?.canDiscovery)!
    }
    
    
    @IBAction func searchButton(sender: AnyObject) {
        if self.canDiscoverDevice(){
            self.connecter?.scanDevice()
        }
    }
    
    //
    @IBAction func connectButton(sender: AnyObject) {
        self.connecter?.connectDevice(self.peripheral)
    }
    
    //押したら光る
    @IBAction func lightButton(sender: AnyObject) {
        if ((self.device?.deviceId) != nil){
            
            //赤色
            BLERequestController.sharedInstance().sendGeneralInformation(nil, text: nil, appName: nil, appNameLocal: nil, package: nil, notifyId: 0, notifyCategoryId: 0, ledSetting: true, vibrationSetting: false, led: nil, vibration: nil, deviceId: (self.device?.deviceId)!, deviceUId: nil, peripheral: self.peripheral, disconnect: false)

        }
    }
    
    
    //デバイス検索が成功したときに呼ばれるデリゲート
    func didDiscoverPeripheral(peripheral: CBPeripheral!, advertisementData: [NSObject : AnyObject]!, RSSI: NSNumber!) {
        if peripheral.name == peripheral.name{
            self.device = self.connecter?.getDeviceByPeripheral(peripheral)
            self.peripheral = peripheral
            self.connectButton.enabled = true;
        }
    }
    
    func didDeviceInitialFinished(peripheral: CBPeripheral!) {
        self.canLighting = peripheral.identifier.UUIDString == self.peripheral?.identifier.UUIDString
        if self.canLighting == true{
            self.lightButton.enabled = true;
        }
    }
    

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

