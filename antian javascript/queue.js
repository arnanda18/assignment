function Node(data) {
  this.data = data;
  this.next = null;
}
function Antrian() {
  this.awal = null;
  this.akhir = null;
}

Antrian.prototype.masuk = function (data) {
  var baru = new Node(data);

  if (this.awal === null) {
    this.awal = baru;
    this.akhir = baru;
  } else {
    this.akhir.next = baru;
    this.akhir = baru;
  }
  console.log("Masuk ke antrian dg value : ", data);
}

Antrian.prototype.keluar = function () {
  var temp;
  if (this.awal !== null) {
    temp = this.awal.data;
    this.awal = this.awal.next;
  }
  console.log("keluar dg value : ", temp);
  return temp;

}

Antrian.prototype.delete_node = function(){
  var temp = this.awal;
  console.log("\n********** DELETE SEMUA NODE *********");
  while(temp != null){
    console.log("Delete node ", temp.data);
    temp = temp.next;
    delete this.awal;
    this.awal=0;

    if (temp != null){
      this.awal = temp;
    }
  }
  console.log("====================================\n");
}

Antrian.prototype.cetak = function () {
  var temp = this.awal;
  let count = 1;
  console.log("\n********* BAGIAN ANTRIAN *********");
  while (temp) {
    console.log("Node ", count, " : ", temp.data);
    temp = temp.next;
    count++;
  }
  console.log("========== AKHIR ANTRIAN ===========\n");
}

var queue = new Antrian();
queue.masuk(100);
queue.masuk(300);
queue.masuk(500);
queue.masuk(700);
queue.masuk(800);
queue.cetak();

queue.keluar();
queue.keluar();
queue.cetak();


queue.delete_node();
