void hash_qp_add(element item, element ht[]){
    int i, hash_value;
    i = hash_value = hash_function(item.key);
    int k = 1;
    
    while(!empty(ht[i])){
        // empty가 아닌 동안 수행
        // 즉, 이미 버킷이 채워짐
        if(equal(ht[i], item)){
            fprintf(stderr, "이미 존재하는 항목임.\n");
            return;
        }
        
        i = (i + k * k) % TABLE_SIZE;
        k++;
        
        if(i == hash_value){
            fprintf(stderr, "저장할 공간 부족.\n");
            return;
        }
    }
    
    ht[i] = item;
}

