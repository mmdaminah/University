//table Initialization
let table3 = [
    [2, 3, -1],
    [1, -1, 3],
    [-1, 1, 2],
];
let table4 = [
    [2, 3, 4],
    [1, 4, 3],
    [4, 1, 2],
    [3, 2, 1],
];
let k = 0;
//.................................. schedule function
function schedule(n, number) {
    if (n == 3)
        for (let i = 0; i < 3; i++)
            for (let j = 0; j < 3; j++) table[i][j] = table3[i][j];
    else if (n == 4)
        for (let i = 0; i < 4; i++)
            for (let j = 0; j < 3; j++) table[i][j] = table4[i][j];
    else {
        let m = n;
        if (m % 2 != 0) m++;
        schedule(m / 2, number);
        copyTopToBottom(m);
        squarelatin(m);
        squarelatinBottom(m);
        if (number != m) 
            fillSpaces(m);
        fillSpacesBottom(m);
        if (n % 2 != 0)
            restForOdd(n, m);
        if (number % 2 != 0) 
            deleteLastRow(n, m);
    }
}
// ............................create square latin..........................
function deleteLastRow(n, m) {
    let temp = [];
    for (i = 0; i < n - 1; i++) temp.push(table[i]);
    for (let i = 0; i < temp.length; i++)
        for (let j = 0; j < temp[i].length; j++)
            if (temp[i][j] == m) temp[i][j] = "-";
    table = temp;
}

function restForOdd(n, m) {
    for (let i = 0; i < n; i++)
        for (let j = 0; j < n; j++) if (table[i][j] == m) table[i][j] = -1000;
}
const squarelatin = (n) => {
    let square = [];
    let temp = [];
    if ((n / 2) % 2 != 0) for (let i = n; i > n - n / 2; i--) temp.push(i);
    else for (let i = n - n / 2 + 1; i <= n; i++) temp.push(i);
    square.push(temp);
    let shift = (array, shifts) => {
        shifts = shifts % array.length;
        let newArr = [...array];
        for (let i = 0; i < shifts; i++) {
            let tempNum = newArr.pop();
            newArr.unshift(tempNum);
        }
        return newArr;
    };
    for (let i = 1; i < n / 2; i++) square.push(shift(square[0], i));
    for (let i = 0; i < n / 2; i++) {
        for (let j = n / 2; j < n; j++) table[i][j] = square[i][j - n / 2];
    }
};
const squarelatinBottom = (n) => {
    for (let i = n / 2; i < n; i++)
        for (let j = n / 2; j < n; j++)
            for (let index = 0; index < n / 2; index++)
                if (table[index][j] == i + 1) table[i][j] = index + 1;
};
function fillSpaces(n) {
    for (let i = 0; i < n / 2; i++) {
        for (let j = 0; j < n / 2; j++) {
            if (table[i][j] < 0) {
                table[i][j] = table[i][n - 1];
                table[i][n - 1] = -10000;
            }
        }
    }
}
function fillSpacesBottom(n) {
    if(n==8)
        return
    else{
        for (let i = n / 2; i < n; i++) {
            for (let j = 0; j < n / 2; j++) {
                if (table[i][j] < 0) {
                    table[i][j] = table[i][n - 1];
                    table[i][n - 1] = -10000;
                }
            }
        }
    }
}

function copyTopToBottom(n) {
    for (let i = 0; i < n / 2; i++)
        for (let j = 0; j < n / 2; j++) {
            if (table[i][j] == -1) table[i + n / 2][j] = -1;
            else table[i + n / 2][j] = table[i][j] + n / 2;
        }
}
// ....................................main................................
let number = 6;
let m = number;
if (m % 2 != 0) m++;
let table = [];
for (let i = 0; i < m; i++) {
    let temp = [];
    for (let j = 0; j < m + 1; j++) temp.push(-1000);
    table.push(temp);
}
schedule(m, number);

for (let i = 0; i < table.length; i++)
    for (let j = 0; j < table[i].length; j++)
        if (table[i][j] < 0) {
            table[i].splice(j, 1);
            j--;
        }

console.log(table);
