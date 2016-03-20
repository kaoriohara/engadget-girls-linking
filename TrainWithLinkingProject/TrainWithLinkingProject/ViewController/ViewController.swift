//
//  ViewController.swift
//  TrainWithLinkingProject
//
//  Created by Aimi Kasama on 2016/03/13.
//  Copyright © 2016年 LinkingTeam1. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        //所要時間・距離
        print("所要時間")
        var distance:Int = 0
        var duration:Int = 0
        let url:NSURL = NSURL(string: "https://maps.googleapis.com/maps/api/distancematrix/json?origins=35.6671414,139.7389042&destinations=35.6713878,139.7327435&mode=walking&language=ja&key=AIzaSyD5iHA_AmmALCwYBcOqqVGuGISMzeD2tIc")!
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
        let timeForWalking:Double = Double(Double(distance)/78)
        let timeForFastWalking:Double = Double(Double(distance)/83)
        let timeForRunning:Double = Double(Double(distance)/100)
        
//        徒歩 4.7kg/h -> 4700 m/h -> 4700 / 60 m/m  -> 78 m/m
//        S2：早歩き5km/h -> 5000m/h -> 5000 / 60 m/m  ->  83 m/m
//        S3：駆け足6km/h -> 6000m/h -> 6000 / 60 m/m  ->  100 m/m

        //所要時間・距離の取得
        print("所要時間（徒歩）：分");
        print(timeForWalking);
        print("所要時間（早歩き）：分");
        print(timeForFastWalking);
        print("所要時間（走る）：分");
        print(timeForRunning);
        print("距離：m");
        print(distance);
        print("所要時間：秒");
        print(duration);
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
}