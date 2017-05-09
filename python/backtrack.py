# -*- coding: utf-8 -*-

bagWeight = int(raw_input('Bag weight: '))
itemNumber = int(raw_input('Item number: '))
itemWeight = []
itemValue = []
for n in range(itemNumber):
    itemWeight.append(int(raw_input('Item weight: ')))
for n in range(itemNumber):
    itemValue.append(int(raw_input('Item value: ')))
maxValue = 0
currentWeight = 0
currentValue = 0

def doBag(index):
    if not isinstance(index,int):
        raise TypeError('index should be an integer')
    if index >= itemNumber:
        return
    
    global currentValue
    global currentWeight
    global maxValue
    
    if currentWeight+itemWeight[index] <= bagWeight:
        currentWeight += itemWeight[index]
        currentValue += itemValue[index]
        if currentValue > maxValue:
            maxValue = currentValue
        doBag(index+1)
        currentWeight -= itemWeight[index]
        currentValue -= itemValue[index]
    
    doBag(index+1)
    return 1

def BagBacktrack():
    print 'doBag...'
    doBag(0)
    
if __name__ == '__main__':
    BagBacktrack()
    print 'Max Value: ', maxValue