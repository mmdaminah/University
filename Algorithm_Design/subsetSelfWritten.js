let numbers = [10, 7, 5, 18, 12, 20, 15];
let sum = 35;
let tempsum = 0;
let j = 0 
function findSubset(numbers, tempsum, sum, i,arr=[]){
    j++;
    console.log(tempsum)
    if(tempsum == sum)
        console.log("found one!!!!", arr);
    if(tempsum > sum){
        return
    }
    if(i === numbers.length)
        return
    if(tempsum < sum){
        arr.push(numbers[i])
        findSubset(numbers, tempsum+numbers[i],sum, i+1,arr)
        arr.pop()
    }
    if(tempsum < sum)
        findSubset(numbers, tempsum,sum, i+1,arr)
}
findSubset(numbers, tempsum,sum, 0) 
console.log("Nodes generated" + " " + j)