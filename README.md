# AVL-Tree
AVL Ağacına Kişi Ekleme, Level Order Yazdırma, yüksekliğini güncel durumlarına göre bulma

<h3>PROJE ÖZETİ</h3>
Projede Kisiler.txt dosyasının içindeki Ad#Yaş#Boy şeklinde ayrılmış, satır satır olan verileri okuyup 
eşzamanlı olarak AVL ağacımıza, okuduğumuz dosyadaki her bir kişinin boyuna göre ekleme 
yapmamız gerekmektedir. Detaylı şekilde ele alacak olursak, projede ilk şart dosya hiyerarşisinin doğru 
olması ve minimum sınıf yapılarıydı. Beklenen diğer şartlar ise şablon yapı kullanılmaması ve her 
sınıfın başlık ve kaynak dosyasının ayrı olmasıydı. Yaptığım aşamalara gelecek olursam, projeyi 3 
parçaya böldüm. İlk yaptığım iş sorun odaklı algoritma çıkarmak oldu. Algoritmayı çıkardıktan 
sonraki adım olarak gerekli başlık ve kaynak dosyalarımı oluşturup sınıflarımı yazdım. Gerekli 
metotları da ihtiyaca göre oluşturduktan sonra son adım olarak Main metodumda çağırmak için 
Processess sınıfı oluşturdum. Bu sınıf içinde bir metot yazıp içinde Kisiler.txt dosyamı okuyarak 
eşzamanlı olarak ağacımı oluşturdum ve metodumun sonunda Level Order şekilde ağacımı yazdırdım. 
Ve geriye Main metodumda bu sınıftan nesne oluşturup bu metodu çağırmak kaldı.


<h3>GELİŞTİRİLEN YAZILIM</h3>
Projeye önce Person sınıfını oluşturarak başladım. Kişi için Ad, yaş ve boy özellikleri oluşturdum.
Sonrasında Main metodumda sadece bir sınıftan nesne oluşturup metodunu çağırmak için Proccesses 
sınıfı oluşturdum. İkinci oluşturduğum sınıfım ise Node sınıfı oldu. AVL ağacıma ekleyeceğim 
düğümün özelliklerini ve metodlarını oluşturdum. Sonraki adımda ise AVLTree yapımı Node ile 
oluşturulacak şekilde ekleme ve diğer metodlarımı yazdım. Projede bizden yüksekliğin ve derinliğin
sürekli güncellenerek yığıtlara atılması istendiği için yükseklik ve derinlik hesaplayan metodlarımı da 
ona göre oluşturdum. Sonrasında Stack yapımı Liste ile oluşturulacak şekilde yazdım ve ilgili 
metodlarımı oluşturdum. Ama AVL ağacı için yazdığım düğüm yapım Stack yapıma uygun olmadığı 
için NodeOfStack isimli bir düğüm sınıfı oluşturdum. Stack yapımda tamamlandıktan sonra AVLTree 
yapımın içinde yükseklik ve derinliği push edebilmek için gerekli işlemleri de gerçekleştirdim. Her adım 
tamamlandıktan sonra Proccesses sınıfımın içinde AddToTreeAndWrite metodumda txt dosyamın 
içindeki verileri okuyarak eşzamanlı olarak Person sınıfımdan nesne oluşturup parametre olarak ise 
dosyadan okuduğum ad, yaş ve boy özelliklerimi verdim. Oluşan kişiyi ise AVL ağacımın ekle 
metoduna parametre olarak vererek ekleme işlemini yaptım. Dosyanın tamamı okunduktan sonra 
ağacımı istenilen formatta yazdırdım.


<h3>ZORLANDIĞIM VE EKSİK KALAN KISIMLAR</h3>
Ağaca eklediğim düğümlerin yükseklik ve derinliğini güncelleyip yığıtlara ekleme işleminde doğru 
sonucu alabilmek çok zorladı. Yükseklikleri üç gün uğraşmamın sonucunda doğru biçimde alabildim 
fakat derinliği yapamadım uğraşmak için vakitte kalmadı. Sonuç olarak ödevimi sadece derinlik için 
hesapladığım değerler yanlış olacak şekilde tamamladım
