// leetcode71.简化路径
/**
 * @param {string} path
 * @return {string}
 */
 var simplifyPath = function(path) {
    // 将 /./ 或以 /. 结尾替换为 / 
    while(/\/\.\/|\/\.$/.exec(path)) {
        path = path.replace(/\/\.\/|\/\.$/,'/');
    }
	// 将重复的斜杠(/) 转换成单个斜杠
    path = path.replace(/(\/)+/g,'/');
	// 匹配 /../ 或者以 /..结尾
    var Index = /\/\.\.\/|\/\.\.$/.exec(path);
	while(Index) {
        let index = Index.index + 1;    // .. 位置
        let flag = 0;   // / 的个数
        let slash = new Array(0, 0); // 记录斜杠的位置
        for(let i = index; i > -1; i--)
        {
            if(flag == 2)
                break;
            if(path[i] == '/')
            {
                slash[flag] = i;
                flag++;
            }
        }
        if(flag == 2)
        {
            let str1 = path.substring(0, slash[1]);
            let str2 = path.substring(slash[0]+3, path.length);
            path = str1 + str2;
        }
        // 如果是 /..或/../example/../ 一个斜杠的情况
        if(flag == 1) {
            path = path.substring(slash[0]+3, path.length);
        }
        Index = /\.\./.exec(path);
    }
	if(path == "/"|| path == "")
        return "/";
    // 如果最后一个目录存在就不能以斜杠结尾
    else if(path[path.length-1] == '/')
        path = path.substring(0, path.length - 1);
    return path;
};