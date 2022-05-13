<html>
    <head>
        <!-- CSS only -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" 
        integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
        
    </head>
    <body>  
        <style>
            @import url('https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;500;600;700;800;900&display=swap');

            .{
                font-family: 'Poppins', sans-serif;
            }

            table{
                width: 100;
                height: 200;
                border: 2px solid;
            }
        </style>

        <?php
    		include "../db.php";
    
		    $idBiodata = $_GET['id_biodata'];
		    $query = mysqli_query($conn, "SELECT * FROM biodata WHERE id_biodata = '$idBiodata'");
		    $data = mysqli_fetch_assoc($query);
		?>

        <div class="container-sm mt-4">
            <h2 class="col-sm-4 mb-4" style="text-align: center;">Form Edit Biodata</h2>
        <form action="../config/update.php" method="POST" enctype="multipart/form-data">
            <input value="<?= $idBiodata ?>"type="text" name="id_biodata" hidden>
            <input value="<?= $data['pass_foto']?>"type="text" name="current_image" hidden>
            <div class="row mb-3 ">
                <label class="col-sm-2 col-form-label">Nama Lengkap</label>
                <div class="col-sm-4">
                <input type="name" name="name" class="form-control" value="<?= $data['nama_lengkap']?>">
                </div>
            </div>
            <div class="row mb-3 ">
                <label class="col-sm-2 form-label">Alamat</label>
                <div class="col-sm-4">
                <textarea class="col-sm-2 form-control" name="alamat" rows="3"><?php echo $data['alamat']?></textarea>
                </div>
            </div>
            <div class="row form-group mb-2">
                        <label for="agama" class="col-sm-2 required">Agama</label>
                        <div class="col-sm-4">
                            <?php
                                $agama = ["Islam","Khatolik","Hindu","Buddha","Konghucu","Kristen"];
                            ?>
                            <select class="col-sm-2 form-select" name="agama" id="agama" required>
                                <?php
                                    foreach ($agama as $nilai) {
                                ?>
                                <option value="<?= $nilai?>" <?= ($result['agama'] === $nilai) ? 'selected' : ''?>><?= $nilai?></option>
                                <?php
                                    }
                                ?>
                            </select>
                        </div>
             </div>
             <div class="row mb-3 ">
                <label class="col-sm-2 col-form-label">Tanggal Lahir</label>
                <div class="col-sm-4">
                <input type="date" name="ttl" class="form-control" value="<?= $data['tgl_lahir']?>">
                </div>
            </div>
            <div class="row mb-3 ">
                <label class="col-sm-2 col-form-label">Pendidikan Terakhir</label>
                <div class="col-sm-4">
                <input type="text" name="pendidikan" class="form-control" value="<?= $data['pendidikan']?>">
                </div>
            </div>
            <div class="row mb-3">
                <label class="col-sm-2 form-label">Jenis Kelamin</label>
                <div class="col-sm-5">
                    <div class="form-check form-check-inline">
                            <input class="col-sm-2 form-check-input" type="radio" name="genre" value="L" <?php if($data['jenis_kelamin']=='L') echo 'checked'?>>
                            <label class="col-sm-2 form-check-label">Male</label>
                    </div>
                    <div class="form-check form-check-inline">
                            <input class="col-sm-2 form-check-input" type="radio" name="genre" value="P" <?php if($data['jenis_kelamin']=='P') echo 'checked'?>>
                            <label class="col-sm-2 form-check-label">Female</label>
                    </div>
                </div>
            </div>
            <div class="row mb-3 ">
                <label class="col-sm-2 col-form-label">Program Studi</label>
                <div class="col-sm-4">
                <input type="alamat" name="prodi" class="form-control" value="<?= $data['program_studi']?>">
                </div>
            </div>
            <div class="row mb-3 ">
                <label class="col-sm-2 col-form-label">Hobbi</label>
                <div class="col-sm-4">
                <input type="alamat" name="hobbi" class="form-control" value="<?= $data['hobbi']?>">
                </div>
            </div>
            <div class="row mb-3 ">
                <label class="col-sm-2 form-label">Keahlian/Skill</label>
                <div class="col-sm-4">
                <textarea class="col-sm-2 form-control" name="keahlian" rows="3"><?= $data['keahlian']?></textarea>
                </div>
            </div>
            <div class="row mb-3 ">
                <label class="col-sm-2 form-label">Pengalaman</label>
                <div class="col-sm-4">
                <textarea class="col-sm-2 form-control" name="pengalaman" rows="3"><?= $data['pengalaman']?></textarea>
                </div>
            </div>
            <div class="row input-group mb-3">
                <label class="col-sm-2 input-group-text" for="input">Foto</label>
                <div class="col-sm-4">
                <input type="file" class="col-sm-2 form-control" id="input" name="pass_foto">
                </div>
            </div>
            <button type="submit" name="submit" class="btn btn-primary">Update Biodata</button>
        </form>
    </div>
</body>
</html>