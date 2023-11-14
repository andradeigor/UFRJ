import java.util.LinkedList;
import java.util.concurrent.atomic.AtomicLong;


//classe da estrutura de dados (recurso) compartilhado entre as threads
class Sa {
  //recurso compartilhado
  private AtomicLong r;
  //construtor
  public Sa(long init) { 
     this.r = new AtomicLong(init); 
  }

  //operacao sobre o recurso compartilhado
  public long get() {
    return r.get();
  }

  //operacao sobre o recurso compartilhado
  public void inc(Long value){
    this.r.addAndGet(value);  
  }
}


class FilaTarefas {
  private final int nThreads;
  private final MyPoolThreads[] threads;
  private final LinkedList<Runnable> queue;
  private boolean shutdown;
  private Sa sa;

  public FilaTarefas(int nThreads, Sa sa) {
    this.shutdown = false;
    this.nThreads = nThreads;
    this.sa = sa;
    queue = new LinkedList<Runnable>();
    threads = new MyPoolThreads[nThreads];
    for (int i = 0; i < nThreads; i++) {
      threads[i] = new MyPoolThreads();
      threads[i].start();
    }
  }

  public void execute(Runnable r) {
    synchronized (queue) {
      if (this.shutdown)
        return;
      queue.addLast(r);
      queue.notify();
    }
  }

  public void shutdown() {
    synchronized (queue) {
      this.shutdown = true;
      queue.notifyAll();
    }
    for (int i = 0; i < nThreads; i++) {
      try {
        threads[i].join();
      } catch (InterruptedException e) {
        return;
      }
    }
  }

  private class MyPoolThreads extends Thread {
    public void run() {
      Runnable r;
      while (true) {
        synchronized (queue) {
          while (queue.isEmpty() && (!shutdown)) {
            try {
              queue.wait();
            } catch (InterruptedException ignored) {
            }
          }
          if (queue.isEmpty() && shutdown)
            return;
          r = queue.removeFirst();
        }
        try {
          r.run();

          Long primes = ((PrimeCheck) r).getPrimes();
          //Soma na classe compartilhada os primos encontrados pela thread
          sa.inc(primes);
        } catch (RuntimeException e) {
        }
      }
    }
  }
}
// -------------------------------------------------------------------------------

// --PASSO 1: cria uma classe que implementa a interface Runnable
class PrimeCheck implements Runnable {
  private Integer value;
  public Long primes;
  //precisa refatorar pra soma não ser feita de um em um, fazer ela de forma global
  public PrimeCheck(Integer value) {
    this.value = value;
    this.primes = 0L;
  }

  private Boolean ehPrimo(Integer n) {
    Integer i;
    if (n <= 1)
      return false;
    if (n == 2)
      return true;
    if (n % 2 == 0)
      return false;
    for (i = 3; i < Math.sqrt(n) + 1; i += 2)
      if (n % i == 0)
        return false;
    return true;
  }


  public Long getPrimes(){return this.primes;}
  // --metodo executado pela thread
  public void run() {
    if(ehPrimo(value)){
      System.out.println("Achei um primo "+ value );
      //Aumenta o valor local de primos que posteriormente será somado
      this.primes++;
    }
  }

}

// Classe da aplicação (método main)
class MyPool {
  private static final int NTHREADS = 10;

  // Variavel que vai guardar o total de números procurados
  private static final int nTotal = 1000000; 
  public static void main(String[] args) {
    // Cria a classe compartilhada entre as threads e inicia ela com 0(total de primos encontrados)
    Sa sa = new Sa(0);
    // --PASSO 2: cria o pool de threads com a classe compartilhada
    FilaTarefas pool = new FilaTarefas(NTHREADS, sa);
    // --PASSO 3: dispara a execução dos objetos runnable usando o pool de threads
    for (Integer i = 0; i <= nTotal; i++) {
      Runnable r = new PrimeCheck(i);
      pool.execute(r);
    }

    // --PASSO 4: esperar pelo termino das threads
    pool.shutdown();
    System.out.println("Achei no total " + sa.get() + " primos!");
    System.out.println("Terminou");
  }
}
