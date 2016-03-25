//
//  RegistrationPrefecture.swift
//  TrainWithLinkingProject
//
//  Created by Aimi Kasama on 2016/03/25.
//  Copyright © 2016年 LinkingTeam1. All rights reserved.
//


class RegistrationPrefecture: UIViewController,UIPickerViewDelegate,UIPickerViewDataSource{
    
    var prefectureList:NSArray!
    var selectPrefecture:String!
    
    @IBOutlet weak var prefecturePicker: UIPickerView!
    
    override func viewDidLoad() {
        prefecturePicker.delegate = self
        prefecturePicker.dataSource = self
        let prefectureUrl:NSURL = NSURL(string: "http://geoapi.heartrails.com/api/json?method=getPrefectures")!
        let prefectureJsonData = NSData(contentsOfURL: prefectureUrl)!
        var json:NSDictionary!
        do{
             json = try NSJSONSerialization.JSONObjectWithData(prefectureJsonData, options: NSJSONReadingOptions.MutableContainers) as! NSDictionary
        }catch{
            
        }
        prefectureList = json.objectForKey("response")?.objectForKey("prefecture") as! NSArray
    }
    func numberOfComponentsInPickerView(pickerView: UIPickerView) -> Int {
        return 1
    }
    
    func pickerView(pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return prefectureList[row] as? String
    }
    
    func pickerView(pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return prefectureList.count
    }
    
    func pickerView(pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        selectPrefecture = prefectureList[row] as? String
    }
    
    @IBAction func gotoCitizen(sender: AnyObject) {
        if selectPrefecture != nil {
            performSegueWithIdentifier("GoToCitizen", sender:nil)
        }
    }

    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "GoToCitizen" {
            let viewController = segue.destinationViewController as! RegisterCitizenViewController
            viewController.prefecture = selectPrefecture
        }
    }
    
}
