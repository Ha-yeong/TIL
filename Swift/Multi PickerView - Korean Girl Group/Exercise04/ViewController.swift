//
//  ViewController.swift
//  Exercise04
//
//  Created by Hayeong Shim on 2017. 5. 5..
//  Copyright © 2017년 Hayeong. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource {
    
    var category = ["트와이스", "걸스데이", "에이핑크"]
    var myDatabase = [
        ["twice나연.jpg", "twice다현.jpg", "twice모모.jpg", "twice미나.jpg", "twice사나.jpg", "twice정연.jpg", "twice지효.jpg", "twice쯔위.jpg", "twice채영.jpg"],
        ["girlsday민아.jpg", "girlsday소진.jpg", "girlsday유라.jpg", "girlsday혜리.jpg"],
        ["apink나은.jpg", "apink남주.jpg", "apink보미.jpg", "apink은지.jpg", "apink초롱.jpg", "apink하영.jpg"]
    ]
    
    var imageArray = [UIImage?]()
    
    @IBOutlet weak var pickerView: UIPickerView!
    @IBOutlet weak var selectedItem: UILabel!
    @IBOutlet weak var imageView: UIImageView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        for i in 0...myDatabase.count-1 {
            for j in 0...myDatabase[i].count-1 {
                let image = UIImage(named: myDatabase[i][j])
                imageArray.append(image)
            }
        }
        
        selectedItem.text = myDatabase[0][0]
        imageView.image = imageArray[0]
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    
    // returns the number of 'columns' to display.
    @available(iOS 2.0, *)
    public func numberOfComponents(in pickerView: UIPickerView) -> Int{
        return 2
    }

    // returns the number of rows in each component..
    @available(iOS 2.0, *)
    public func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int{
        if component == 0 {
            return myDatabase.count
        }
        else {
            let selectedValue: Int = pickerView.selectedRow(inComponent: 0)
            return myDatabase[selectedValue].count
        }
    }
    
    // returns the title for rows in each component
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        let selectedValue: Int = pickerView.selectedRow(inComponent: 0)
        if component == 0 {
            return category[row]
        }
        else {
            return myDatabase[selectedValue][row]
        }
    }
    
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        let selectedValue: Int = pickerView.selectedRow(inComponent: 0)
        pickerView.reloadAllComponents()    //이 코드 한줄로 'out of range' 에러가 사라짐
        
        var imageNum = 0
        if selectedValue > 0 {
            for i in 1...selectedValue {
                imageNum = imageNum + myDatabase[i-1].count
            }
        }
        selectedItem.text = myDatabase[selectedValue][row]
        imageView.image = imageArray[imageNum + row]
    }
}

