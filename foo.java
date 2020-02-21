//1114 按序打印 https://leetcode-cn.com/problems/print-in-order/submissions/
//通过CountDownLatch实现三个函数在三个线程中顺序执行
//todo :CountDownLatch源码分析 以及和 cyclicbarrier区别


class Foo {
    private CountDownLatch c2;
    private CountDownLatch c3;
    public Foo() {
        c2=new CountDownLatch(1);
        c3=new CountDownLatch(1);
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        c2.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        c2.await();
        printSecond.run();
        c3.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
        c3.await();
        printThird.run();
    }
}
//额外方法volatile while自旋锁等待前一个函数释放