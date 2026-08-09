
        cin>>arr[i];
    }

    vector<int> isPrime(200001,1);

    isPrime[0] = 0;
    isPrime[1] = 0;
    vector<int> primes;

    for(int i=2;i<=200000;i++)
    {
        if(isPrime[i])
        {