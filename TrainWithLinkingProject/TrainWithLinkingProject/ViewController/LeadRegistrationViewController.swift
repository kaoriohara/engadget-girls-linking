//
//  LeadRegistrationViewController.swift
//  TrainWithLinkingProject
//
//  Created by Aimi Kasama on 2016/03/25.
//  Copyright © 2016年 LinkingTeam1. All rights reserved.
//


class LeadRegistrationViewController: BWWalkthroughPageViewController {

    @IBAction func RegistAction(sender: AnyObject) {
        let storyboard = UIStoryboard(name: "Registration", bundle: nil)
        let viewController = storyboard.instantiateInitialViewController()!
        self.presentViewController(viewController, animated: true, completion: nil)
        
    }
}
