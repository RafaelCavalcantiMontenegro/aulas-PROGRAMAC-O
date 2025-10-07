import java.io.Console;

public class divisaopor0 {
    try
{
int divisor = 0;
int resultado = 10 / divisor; // Gera uma exceção
}
catch (DivideByZeroException ex)
{
Console.WriteLine($"Erro: {ex.Message}");
throw; // Relança a exceção para ser tratada em outro nível
}
finally
{
Console.WriteLine("Bloco finally executado.");
}
}