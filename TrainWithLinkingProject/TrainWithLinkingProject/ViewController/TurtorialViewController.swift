//
//  TurtorialViewController.swift
//  TrainWithLinkingProject
//
//  Created by Aimi Kasama on 2016/03/25.
//  Copyright © 2016年 LinkingTeam1. All rights reserved.
//

//import Cocoa

class TurtorialViewController: UIViewController,BWWalkthroughViewControllerDelegate {
    
    override func viewDidLoad() {
    }
    
    override func viewDidAppear(animated: Bool) {
        let board = UIStoryboard(name: "onBoarding", bundle: nil)
        let walkthrough = board.instantiateViewControllerWithIdentifier("walk100") as! BWWalkthroughViewController
        let walkZero = board.instantiateViewControllerWithIdentifier("walk0")
        let walkOne = board.instantiateViewControllerWithIdentifier("walk1")
        let walkTwo = board.instantiateViewControllerWithIdentifier("walk2")
        let walkThree = board.instantiateViewControllerWithIdentifier("walk3")
        let walkFour = board.instantiateViewControllerWithIdentifier("walk4")
        
        walkthrough.delegate = self
        walkthrough.addViewController(walkZero)
        walkthrough.addViewController(walkOne)
        walkthrough.addViewController(walkTwo)
        walkthrough.addViewController(walkThree)
        walkthrough.addViewController(walkFour)
        
        self.presentViewController(walkthrough, animated: true, completion: nil)

    }
}
