function solution(enroll, referral, seller, amount) {
    var answer = [];
    
    const moneyMap = new Map();
    
    const adj = enroll.reduce((acc, cur, index)=> {
        acc[cur] = referral[index];
        return acc;
    }, {})
    
    seller.forEach((s, index)=> {
        let curMoney = amount[index] * 100;
        let curPerson = s;
        
        while(adj[curPerson]) {  
            if(moneyMap[curPerson] === undefined) {
                moneyMap[curPerson] = 0;
            }
            
            const tmp = Math.floor(curMoney * 0.1)
            
            if(tmp< 1) {
                moneyMap[curPerson] += curMoney;
                break;
            }
            
            moneyMap[curPerson] += (curMoney - tmp);
            curMoney = tmp;
            curPerson = adj[curPerson];
        }
    })
    
    return enroll.map(e=> moneyMap[e] ?? 0);
}