<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>UTS Praktikum Pemrograman Web</title>
  <link rel="stylesheet" type="text/css" href="css/style.css">
	<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
</head>
<body>
  
  <div class="container">
    <h2>Welcome to my Biodata</h2>
  	<div class="row justify-content-center pt-4">
      
      <div class="col-6">
        <table class="table" border="1">
          <a class="btn btn-primary" href="pages/insert.php" role="button">Add</a>
          
          <?php 
            include "db.php";
            $query = mysqli_query($conn,"SELECT * FROM biodata") or die(mysqli_error($conn));
            while ($data = mysqli_fetch_array($query)) {

            ?>
          <tr>
            <td  scope="row">Name </td>
            <td >: <?= $data['nama_lengkap'] ?></td>
          </tr>
          <tr>
            <td>Alamat</td>
            <td>: <?= $data['alamat'] ?> </td>
          </tr>
          <tr>
            <td>Agama</td>
            <td>: <?= $data['agama'] ?></td>
          </tr>
          <tr>
            <td>Tanggal Lahir</td>
            <td>: <?= $data['tgl_lahir'] ?></td>
          </tr>
          <tr>
            <td>Pendidikan Terakhir</td>
            <td>: <?= $data['pendidikan'] ?></td>
          </tr>
          <tr>
            <td>Jenis kelamin</td>
            <td>: <?= $data['jenis_kelamin'] ?></td>
          </tr>
          <tr>
            <td>Program Studi</td>
            <td>: <?= $data['program_studi'] ?></td>
          </tr>
          <tr>
            <td>Hobbi</td>
            <td>: <?= $data['hobbi'] ?></td>
          </tr>
          <tr>
            <td>Keahlian</td>
            <td>: <?= $data['keahlian'] ?></td>
          </tr>
          <tr>
            <td>Pengalaman</td>
            <td>: <?= $data['pengalaman'] ?></td>
          </tr>
          <tr>
            <td>Foto</td>
            <td class="pass_foto_bio"> <img height="200" width="auto"  src="images/<?= $data['pass_foto'] ?>"> </td>
          </tr>
          <tr>
            <td></td>
            <td class="btn-change-form">
              <a class="btn btn-primary" href="pages/update.php?id_biodata=<?= $data['id_biodata'] ?>" role="button">Update</a>
              <a class="btn btn-primary" href="config/delete.php?id_biodata=<?= $data['id_biodata'] ?>" role="button">Delete</a>
            </td>
          </tr>    
          <?php 
        } 
          ?> 
        </table>
        
      </div>
      
    </div>
  </div>

</body>
</html>