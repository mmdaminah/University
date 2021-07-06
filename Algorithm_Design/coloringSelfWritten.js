let vertices = 4;
let graph = [
     [ 0, 1, 1, 1 ],
     [ 1, 0, 1, 0 ],
     [ 1, 1, 0, 1 ],
     [ 1, 0, 1, 0 ],
];
let colors = new Array(vertices).fill(-1);
let numberOfColores = 3;
function colorGraph(graph, vertices, numberOfColores, i, colors){
    if(isAnswer(vertices) && colorsOk(graph, vertices, colors)){
        console.log("these colores are ok!", colors);
    }
    if(i == vertices)
        return
    for(let j = 0; j < numberOfColores; j++){
        colors[i] = j;
        if(colorsOk(graph, vertices, colors))
            colorGraph(graph, vertices, numberOfColores, i+1, colors)
            colors[i] = -1;
    }
}
function colorsOk(graph, vertices, colors){
    for(let i = 0; i < vertices; i++)
        for(let j = i+1; j < vertices; j++)
            if(graph[i][j] && colors[i]!=-1  && colors[i] == colors[j])
                return false;
    return true;
}
function isAnswer(vertices){
    for(let i = 0; i < vertices; i++)
        if(colors[i]==-1)
            return false
    return true
}
colorGraph(graph, vertices, numberOfColores, 0, colors)