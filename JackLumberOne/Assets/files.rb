
fname = "Images/Buttons.txt"

somefile = File.open(fname,"w")

Dir.foreach("Images/Buttons/"){|x| temp = x[0...-7] 
somefile.puts "#{temp}"}
somefile.close

somefile = File.open("Images/Backgrounds.txt","w")
Dir.foreach("Images/Backgrounds/"){|x| temp = x[0...-7] 
somefile.puts "#{temp}"}
somefile.close
somefile = File.open("Images/GUI.txt","w")
Dir.foreach("Images/GUI/"){|x| temp = x[0...-7] 
somefile.puts "#{temp}"}
somefile.close
somefile = File.open("Images/Projectiles.txt","w")
Dir.foreach("Images/Projectiles/"){|x| temp = x[0...-7] 
somefile.puts "#{temp}"}
somefile.close
somefile = File.open("Images/Player.txt","w")
Dir.foreach("Images/Sprites/Player/"){|x| temp = x[0...-7] 
somefile.puts "#{temp}"}
somefile.close
somefile = File.open("Images/Enemies.txt","w")
Dir.foreach("Images/Sprites/Enemies/"){|x| temp = x[0...-7] 
somefile.puts "#{temp}"}
somefile.close
somefile = File.open("Images/Bosses.txt","w")
Dir.foreach("Images/Sprites/Bosses/"){|x| temp = x[0...-7] 
somefile.puts "#{temp}"}
somefile.close
