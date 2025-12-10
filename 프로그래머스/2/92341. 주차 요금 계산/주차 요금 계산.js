function solution(fees, records) {
    var answer = [];
    const [defaultMin, defaultFee, unitMin,feePerMin] = fees
    
    const m1 = {}; // 주차 기록 계산
    const m2 = {}; // 결과 객체
    
    // 주차 시간 계산
    records.forEach((record)=>{
        const [time, carNum, dir] = record.split(' ')
        const [h, m] = time
        .split(':')
        .map(Number)
        
        const totalMinute = h * 60 + m
        
        if(m1[carNum] === undefined) {
            m1[carNum] = totalMinute;
            return;   
        }
        
        if(!m2[carNum]) {
            m2[carNum] = 0;
        }
        
        m2[carNum] += totalMinute - m1[carNum];
        m1[carNum] = undefined;
    })
    
    const LAST_TIME = 23 * 60 + 59;
    
    // 출차 기록 없는 예외 처리
    Object.entries(m1).forEach(([key, value])=> {
        if(value === undefined) {
            return;
        }
        
        if(!m2[key]) {
            m2[key] = 0;
        }
        
        m2[key] += LAST_TIME - value;
    })
    
    // 요금 계산
    answer = Object.entries(m2)
        .map(([key, value])=> {
            if(value < defaultMin) {
                return [key, defaultFee];
            }
        
            const resultFee = defaultFee + Math.ceil((value-defaultMin)/unitMin) * feePerMin;
        
            return [key, resultFee];
        })
        .sort(([aKey], [bKey]) => aKey - bKey)
        .map(([,value]) => value)
    
    return answer;
}