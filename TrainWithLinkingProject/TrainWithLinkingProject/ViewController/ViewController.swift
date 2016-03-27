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
    var timeByWalk:Float?
    var timeByTooWalk:Float?
    var timeByRunning:Float?
    
    var trainTimeByWalk:NSDate?
    var trainTimeByFastWalk:NSDate?
    var trainTimeByRunning:NSDate?
    

    @IBOutlet weak var searchButton: UIButton!
    @IBOutlet weak var connectButton: UIButton!
    @IBOutlet weak var lightButton: UIButton!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        connecter = BLEConnecter.sharedInstance()
        connecter?.addListener(self, deviceUUID: nil)
        connectButton.enabled = false;
        lightButton.enabled = false;
        
//        getDistanceAndTime()
//        
//        trainTimeByWalk = getCanRideTime(round(timeByWalk!))
//        trainTimeByFastWalk = getCanRideTime(round(timeByTooWalk!))
//        trainTimeByRunning = getCanRideTime(round(timeByRunning!))
        print("aa")
        
        
        
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
    
    func getCanRideTime(inter:Float) ->NSDate{
        let nowFormatter = NSDateFormatter()
        nowFormatter.dateFormat = "HH:mm"
        let nowTime = NSDate()
        let calendar = NSCalendar(identifier: NSCalendarIdentifierGregorian)
        let comps:NSDateComponents = (calendar?.components([.Year, .Month, .Day, .Hour, .Minute], fromDate: nowTime))!
        //parameter はかおりさんのものを入れる
        let afterTen = NSDate(timeIntervalSinceNow:Double(inter)*60 + 60*60*9)
        print("現在時刻")
        let trainData:NSArray = getTrainTime()
        
        for i in 0..<trainData.count{
            let timeStr = trainData[i] as! String
            let a = timeStr.characters.split{$0 == ":"}.map(String.init)
            comps.hour = Int(a[0])!
            comps.minute = Int(a[1])!
            var traintime = calendar?.dateFromComponents(comps)
            traintime = NSDate(timeInterval: 60*60*9, sinceDate: traintime!)
            //            let targetTime:NSDate;
            if afterTen.compare(traintime!) == NSComparisonResult.OrderedAscending{
                print("次に乗れる電車！")
                targetTrainTime = traintime!
                break
            }else{
                print("過ぎてる")
            }
        }
        
        print(targetTrainTime)
        return targetTrainTime!
    }
    
    func getDistanceAndTime(){
        //所要時間・距離
        print("所要時間")
        var distance:Int = 0
        var duration:Int = 0
        
        let origin = "35.6671414,139.7389042" //赤坂アークヒルズ（アーク森ビル）
        let destination = "35.6713878,139.7327435" //赤坂駅
        
        let url:NSURL = NSURL(string: "https://maps.googleapis.com/maps/api/distancematrix/json?origins="+origin + "&destinations=" + destination+"&mode=walking&language=ja&key=AIzaSyD5iHA_AmmALCwYBcOqqVGuGISMzeD2tIc")!
        let jsonData = NSData(contentsOfURL: url)!
        do {
            let json = try NSJSONSerialization.JSONObjectWithData(jsonData, options: NSJSONReadingOptions.MutableContainers) as! NSDictionary
            let rows = json["rows"] as! NSArray
            let elements = rows[0]["elements"] as! NSArray
            let element = elements[0] as! NSDictionary
            let distanceDic = element["distance"] as! NSDictionary
            let durationDic = element["duration"] as! NSDictionary
            
            distance = distanceDic["value"] as! Int
            duration = durationDic["value"] as! Int
            
        }catch{
            
        }
        let timeForWalking:Float = Float(Double(distance)/78)
        let timeForFastWalking:Float = Float(Double(distance)/83)
        let timeForRunning:Float = Float(Double(distance)/100)
        
        //        徒歩 4.7kg/h -> 4700 m/h -> 4700 / 60 m/m  -> 78 m/m
        //        S2：早歩き5km/h -> 5000m/h -> 5000 / 60 m/m  ->  83 m/m
        //        S3：駆け足6km/h -> 6000m/h -> 6000 / 60 m/m  ->  100 m/m
        //        google distancematrix api limit!! 2500 request/day
        
        //所要時間・距離の取得
        print("所要時間（徒歩）：分");
        print(timeForWalking);
        timeByWalk = timeForWalking
        print("所要時間（早歩き）：分");
        print(timeForFastWalking);
        timeByTooWalk = timeForFastWalking
        print("所要時間（走る）：分");
        print(timeForRunning);
        timeByRunning = timeForRunning
        print("距離：m");
        print(distance);
        print("所要時間：秒");
        print(duration);
    }
    
    func didFailToConnectPeripheral(peripheral: CBPeripheral!, error: NSError!) {
        
    }
    
    func didConnectDevice(setting: BLEDeviceSetting!) {
        
        getDistanceAndTime()
        
        trainTimeByWalk = getCanRideTime(round(timeByWalk!))
        trainTimeByFastWalk = getCanRideTime(round(timeByTooWalk!))
        trainTimeByRunning = getCanRideTime(round(timeByRunning!))

        
        print("乗りたい時間")
        print(targetTrainTime)
        
        print(trainTimeByWalk)
        print(trainTimeByFastWalk)
        print(trainTimeByRunning)
        //        if( nowtime+12 > Train_t)
        
//        bywalk<traintime きみどり
//        fast < train && train < bywalk
        
//        run < train && train < fast 赤
//        fast < train  train < bywalk　オレンジ
//        bywalk < train きみどり
        
        if (targetTrainTime?.compare(trainTimeByFastWalk!) == NSComparisonResult.OrderedAscending){
            //赤
            setting.settingInformationDataLED .setObject(1, forKey: "settingColorNumber")
            
        }else if (targetTrainTime?.compare(trainTimeByWalk!) == NSComparisonResult.OrderedAscending){
            //おれんじ
            setting.settingInformationDataLED .setObject(3, forKey: "settingColorNumber")
        }else if trainTimeByWalk?.compare(targetTrainTime!) == NSComparisonResult.OrderedAscending{
            //キミドリ
            setting.settingInformationDataLED .setObject(2, forKey: "settingColorNumber")
        }else{
            setting.settingInformationDataLED .setObject(2, forKey: "settingColorNumber")
        }
        
        
        //今の時間+徒歩
        
        //今の時間+早歩き
//         現時刻+走る
        
        
        
        
//        MARK:ここで次の電車まで何分あるかによって色の指定をする
        
        
//        settingColorNumber = 2 キミドリ
//        settingColorNumber = 3 オレンジ
        
        //settingColorNumberで色指定
//        setting.settingInformationDataLED .setObject(1, forKey: "settingColorNumber")
//        print(setting.settingInformationDataLED)
    }
    
    
    func getTrainTime() -> NSMutableArray{
        //時刻表
        print("時刻表")
        let timeArray:NSMutableArray = [];
        let url:NSURL = NSURL(string: "https://api.tokyometroapp.jp/api/v2/datapoints?rdf:type=odpt:StationTimetable&owl:sameAs=odpt.StationTimetable:TokyoMetro.Chiyoda.Akasaka&acl:consumerKey=b31ff347108b7a7b4682c4fb5379da5e45a794498be058c943930076dd492a23")!
        //nilになるかも
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
        lightButton.enabled = false
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
//        Linking Board32932 or Linking DB31 00030
        if peripheral.name == "Linking DB31 00030"{
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

