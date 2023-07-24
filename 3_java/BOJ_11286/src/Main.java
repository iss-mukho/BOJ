import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		PriorityQueue<Num> pq = new PriorityQueue<>();
		int N = Integer.parseInt(br.readLine());

		while (N-- > 0) {
			int x = Integer.parseInt(br.readLine());

			if (x == 0) {
				if (pq.isEmpty())
					bw.write(0 + "\n");
				else
					bw.write(pq.poll() + "\n");
				continue;
			}
			pq.add(new Num(x));
		}

		bw.flush();
		br.close();
		bw.close();
	}
}

class Num implements Comparable<Num> {
	int number;

	public Num(int number) {
		this.number = number;
	}

	@Override
	public String toString() {
		return String.valueOf(this.number);
	}

	@Override
	public int compareTo(Num o) {
		int a = Math.abs(this.number);
		int b = Math.abs(o.number);

		if (a == b) {
			return this.number - o.number;
		} else {
			return a - b;
		}
	}

}