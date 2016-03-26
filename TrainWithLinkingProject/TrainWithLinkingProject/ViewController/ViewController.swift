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
    var targetTrainTime:NSDate?

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
        let nowTime = NSDate()
        let calendar = NSCalendar(identifier: NSCalendarIdentifierGregorian)
        let comps:NSDateComponents = (calendar?.components([.Year, .Month, .Day, .Hour, .Minute], fromDate: nowTime))!
        //parameter はかおりさんのものを入れる
        let afterTen = NSDate(timeIntervalSinceNow: 60*10+60*60*9)
        print("現在時刻")
        let trainData:NSArray = getTrainTime()
        
        for i in 0..<trainData.count{
            let timeStr = trainData[i] as! String
            let a = timeStr.characters.split{$0 == ":"}.map(String.init)
            comps.hour = Int(a[0])!
            comps.minute = Int(a[1])!
            var traintime = calendar?.dateFromComponents(comps)
            traintime = NSDate(timeInterval: 60*60*9, sinceDate: traintime!)
            let targetTime:NSDate;
            if afterTen.compare(traintime!) == NSComparisonResult.OrderedAscending{
                print("まだいける！")
                targetTrainTime = traintime!
                break
            }else{
                print("過ぎてる")
            }
        }
        
        print(targetTrainTime)
        
        
        
//        for( i =0; i<trainData.length; i++){
//            if (nowtime+10 < getTrainTime[i])
//                i++
//            else if( nowtime+10 > getTrainTime[i])
//                Train_t = getTrainTime[i]
//            break;
//        }
//        print("Train_t")
//        print(Train_t)
//        
//        if( nowtime+12 > Train_t)
        
        
        
   }
    
    func didFailToConnectPeripheral(peripheral: CBPeripheral!, error: NSError!) {
        
    }
    
    func didConnectDevice(setting: BLEDeviceSetting!) {
//        MARK:ここで次の電車まで何分あるかによって色の指定をする
        
        
//        settingColorNumber = 2 キミドリ
//        settingColorNumber = 3 オレンジ
        
        //settingColorNumberで色指定
        setting.settingInformationDataLED .setObject(1, forKey: "settingColorNumber")
        print(setting.settingInformationDataLED)
    }
    
    
    func getTrainTime() -> NSMutableArray{
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
                let time = dict.objectAtIndex(i).objectForKey("odpt:departureTime") as! NSString
                timeArray.addObject(time)
            }
        }catch{
            
        }
        
        //時刻表の取得
        print(timeArray)
        
        return timeArray
    }
    
    func canDiscoverDevice()->Bool{
        return (self.connecter?.canDiscovery)!
    }
    
    
    @IBAction func searchButton(sender: AnyObject) {
        if self.canDiscoverDevice(){
            self.connecter?.scanDevice()
        }
    }
    
    @IBAction func connectButton(sender: AnyObject) {
        self.connecter?.connectDevice(self.peripheral)
    }
    
    //押したら光る
    @IBAction func lightButton(sender: AnyObject) {
        if ((self.device?.deviceId) != nil){
            BLERequestController.sharedInstance().sendGeneralInformation(nil, text: nil, appName: nil, appNameLocal: nil, package: nil, notifyId: 0, notifyCategoryId: 0, ledSetting: true, vibrationSetting: false, led: nil, vibration: nil, deviceId: (self.device?.deviceId)!, deviceUId: nil, peripheral: self.peripheral, disconnect: false)
        }
    }
    
    
    //デバイス検索が成功したときに呼ばれるデリゲート
    func didDiscoverPeripheral(peripheral: CBPeripheral!, advertisementData: [NSObject : AnyObject]!, RSSI: NSNumber!) {
        print(peripheral.name)
        if peripheral.name == "Linking Board32932"{
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

