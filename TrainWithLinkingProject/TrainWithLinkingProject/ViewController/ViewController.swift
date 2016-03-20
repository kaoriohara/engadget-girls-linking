//
//  ViewController.swift
//  TrainWithLinkingProject
//
//  Created by Aimi Kasama on 2016/03/13.
//  Copyright © 2016年 LinkingTeam1. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
//    let timeCount:

    override func viewDidLoad() {
        super.viewDidLoad()
        
        //現在時刻
        let nowFormatter = NSDateFormatter()
        nowFormatter.dateFormat = "HH:mm"
        let nowTime = nowFormatter.stringFromDate(NSDate())
        print("現在時刻")
        print(nowTime)

        //時刻表
        print("時刻表")
        let timeArray:NSMutableArray = [];
        let url:NSURL = NSURL(string: "https://api.tokyometroapp.jp/api/v2/datapoints?rdf:type=odpt:StationTimetable&owl:sameAs=odpt.StationTimetable:TokyoMetro.Namboku.AkabaneIwabuchi&acl:consumerKey=b31ff347108b7a7b4682c4fb5379da5e45a794498be058c943930076dd492a23")!
        let jsonData = NSData(contentsOfURL: url)!
        do {
            let json = try NSJSONSerialization.JSONObjectWithData(jsonData, options: NSJSONReadingOptions.MutableContainers) as! NSArray
            let dict = json.objectAtIndex(0).objectForKey("odpt:saturdays") as! NSArray;
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

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

