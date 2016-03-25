//
//  RegisterCitizenViewController.swift
//  TrainWithLinkingProject
//
//  Created by Aimi Kasama on 2016/03/25.
//  Copyright © 2016年 LinkingTeam1. All rights reserved.
//


class RegisterCitizenViewController: UIViewController {
    var prefecture:String!
    var citizenList:NSArray!
    
    override func viewDidLoad() {
        print(prefecture)
        prefecture = prefecture.stringByAddingPercentEncodingWithAllowedCharacters(NSCharacterSet.URLQueryAllowedCharacterSet())!
        let url:String = "http://geoapi.heartrails.com/api/json?method=getCities&prefecture=" + prefecture
        let prefectureUrl:NSURL = NSURL(string: url)!
        let prefectureJsonData = NSData(contentsOfURL: prefectureUrl)!
        var json:NSDictionary!
        do{
            json = try NSJSONSerialization.JSONObjectWithData(prefectureJsonData, options: NSJSONReadingOptions.MutableContainers) as! NSDictionary
        }catch{
            
        }
        citizenList = json.objectForKey("response")?.objectForKey("location") as! NSArray
        print(citizenList);
    }
}
