import java.rmi.*;
import javax.swing.*;
import java.util.Scanner;
import java.lang.Thread.*;
import java.util.ArrayList;
import java.rmi.RemoteException;
public class Cliente {
	public static void main( String args[] ) {
		System.out.println("Iniciando conexao com o servidor...");
		String user, pass;
		Scanner scanner = new Scanner(System.in);
		System.out.print("Usuario:");
		user = scanner.nextLine();
		System.out.print("Senha:");
		pass = scanner.nextLine();
		int mensagenslidas = 0;
		String msg = "";
		while (true)
		try 
		{
			final ServidorChat chat = (ServidorChat) Naming.lookup( "//127.0.0.1:1098/ServidorChat" );
			Thread thread = new Thread(new Runnable() {
				int cont = 0;
				@Override
				public void run()
				{
					try 
					{
						if (chat.connect(user, pass))
						{
							while(true)
							{
								if (chat.get_num_messages() > cont)
								{
									System.out.println(chat.get_message(cont));
									cont++;
								}
							}
						}
						else
						{
							System.out.println("Usuario e/ou senha incorreta.");
							System.exit(0);
						}
					} catch ( Exception e )
					{
						System.out.println("Reestabelecendo conexão.");
					}
				}
			});
			thread.start();
			while(!msg.equals("exit"))
			{
				msg = scanner.nextLine();
				if (msg.equals("exit"))
				{
					chat.disconnect();
					System.exit(0);
				}
				else
					chat.send_message(user+": "+msg);
			}
		}catch( Exception e )
		{ 
			System.out.println("Reestabelecendo conexão.");
		}
	}
}
