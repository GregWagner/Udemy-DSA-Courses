function countDown(num: number) {
    if (num <= 0) {
        console.log("All Done!");
        return;
    }
    console.log(num);
    countDown(num - 1);
}

countDown(5);
