let puzzle = [[7,2,4],[5," ",6],[8,3,1]]
let goalPuzzle = [[1,2,3],[4,5," "],[7,8,6]]
let priorityQueue = []
let inspectedList = []
//get input
// for(let i = 0; i < 3; i++){
//     let temp = []
//     for(let j=0; j < 3 ; j++){
//         let number = prompt("enter number:")
//         temp.push(+number)
//     }
//     puzzle.push(temp)
// }
function findHeuristic(puzzle, goalPuzzle){
    let heuristics = [0,0,0,0,0,0,0,0,0]
    for(let i = 0;i < 3;i++)
        for(let j = 0;j < 3 ;j++)
            loop:for(let k = 0;k < 3;k++)
                for(let m = 0;m < 3 ;m++){
                    if(goalPuzzle[i][j] == puzzle[k][m] && goalPuzzle[i][j]!=" "){
                        heuristics[goalPuzzle[i][j]-1] = Math.abs(i-k)+ Math.abs(j-m)
                        break loop
                    }
                }
    let heuristic = 0          
    heuristics.forEach((item)=> heuristic+=item)
    return heuristic
} 
function fnidGap(puzzle){
    for(let i = 0;i < 3;i++)
        for(let j = 0;j < 3 ;j++)
            if(puzzle[i][j] == " ")
                return [i,j]
}
function possibleMoves(gap){
    if(gap[0]==0 && gap[1]==0)
        return ["down", "right"]
    else if(gap[0]==0 && gap[1]==1)
        return ["down", "right", "left"]
    else if(gap[0]==0 && gap[1]==2)
        return ["down", "left"]
    else if(gap[0]==1 && gap[1]==0)
        return ["up","down", "right"]
    else if(gap[0]==1 && gap[1]==1)
        return ["up","down", "right", "left"]
    else if(gap[0]==1 && gap[1]==2)
        return ["up","down", "left"]
    else if(gap[0]==2 && gap[1]==0)
        return ["up", "right"]
    else if(gap[0]==2 && gap[1]==1)
        return ["up", "right", "left"]
    else if(gap[0]==2 && gap[1]==1)
        return ["up", "left"]
}
function move(puzzle){
    let allowedMoves = [...possibleMoves(fnidGap(puzzle))]
    for(let move of allowedMoves){
        switch(move){
            case "up":
                moveUp(puzzle)
                break
            case "right":
                moveRight(puzzle)
                break
            case "down":
                moveDown(puzzle)
                break 
            case "left":
                moveLeft(puzzle)
                break
        }
    }
}
function moveUp(puzzle){
    let gap = fnidGap(puzzle)
    let newPuzzle = []
    for(let i = 0; i < 3; i++){
        let temp = []
        for(let j=0; j < 3 ; j++){
                temp.push(puzzle[i][j])
            }
            newPuzzle.push(temp)
        }
    newPuzzle[gap[0]][gap[1]] = puzzle[gap[0]-1][gap[1]]
    newPuzzle[gap[0]-1][gap[1]] = " "
    let heuristic = findHeuristic(newPuzzle,goalPuzzle)
    priorityQueue.push({
        "puzzle":[...newPuzzle],
        "heuristic": heuristic 
    })
}
function moveDown(puzzle){
    let gap = fnidGap(puzzle)
    let newPuzzle = []
    for(let i = 0; i < 3; i++){
        let temp = []
        for(let j=0; j < 3 ; j++){
                temp.push(puzzle[i][j])
            }
            newPuzzle.push(temp)
        }
    newPuzzle[gap[0]][gap[1]] = puzzle[gap[0]+1][gap[1]]
    newPuzzle[gap[0]+1][gap[1]] = " "
    let heuristic = findHeuristic(newPuzzle,goalPuzzle)
    priorityQueue.push({
        "puzzle":[...newPuzzle],
        "heuristic": heuristic 
    })
}
function moveRight(puzzle){
    let gap = fnidGap(puzzle)
    let newPuzzle = []
    for(let i = 0; i < 3; i++){
        let temp = []
        for(let j=0; j < 3 ; j++){
                temp.push(puzzle[i][j])
            }
            newPuzzle.push(temp)
        }
    newPuzzle[gap[0]][gap[1]] = puzzle[gap[0]][gap[1]+1]
    newPuzzle[gap[0]][gap[1]+1] = " "
    let heuristic = findHeuristic(newPuzzle,goalPuzzle)
    priorityQueue.push({
        "puzzle":[...newPuzzle],
        "heuristic": heuristic 
    })
}
function moveLeft(puzzle){
    let gap = fnidGap(puzzle)
    let newPuzzle = []
    for(let i = 0; i < 3; i++){
        let temp = []
        for(let j=0; j < 3 ; j++){
                temp.push(puzzle[i][j])
            }
            newPuzzle.push(temp)
        }
    newPuzzle[gap[0]][gap[1]] = puzzle[gap[0]][gap[1]-1]
    newPuzzle[gap[0]][gap[1]-1] = " "
    let heuristic = findHeuristic(newPuzzle,goalPuzzle)
    priorityQueue.push({
        "puzzle":[...newPuzzle],
        "heuristic": heuristic 
    })
}
function isEqual(puzzle, goalPuzzle){
    for(let i = 0;i < 3;i++)
        for(let j = 0;j < 3 ;j++)
            if(puzzle[i][j]!=goalPuzzle[i][j])
                return false
    return true
}
function priority(queue){
    let min = queue[0].heuristic
    let i
    for(i = 0;i < queue.length; i++)
        if(queue[i].heuristic < min)
            min = i
    return min
}
let deleteByIndex = (arr, index)=>{
    if(index > arr.length-1)
        return "out of range"
    else if(arr.length < 2)
        return []
    else if(index == arr.length-1 ){
        arr.pop()
        return arr     
    }
    else if(index == 0){
        arr.shift()
        return arr
    }
    else{
        let subArr1 = arr.slice(0,index)
        let subArr2 = arr.slice(index+1,arr.length)
        return subArr1.concat(subArr2)
    }
}
let tempPuzzle = [...puzzle]
move(tempPuzzle)
let index = priority(priorityQueue)
tempPuzzle = [...priorityQueue[index].puzzle]
if(isEqual(tempPuzzle,goalPuzzle)){
    console.log("found it!!!")
}
else{
    while(true){
        move(tempPuzzle)
        index = priority(priorityQueue)
        tempPuzzle = [...priorityQueue[index].puzzle]
        if(isEqual(tempPuzzle,goalPuzzle)){
            console.log("found it!!!")
            break
        }
        else{
            priorityQueue = deleteByIndex(priorityQueue,index)
        }
    }
}
