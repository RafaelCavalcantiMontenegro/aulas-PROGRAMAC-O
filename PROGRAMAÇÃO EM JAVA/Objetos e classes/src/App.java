public class App {
    public static void main(String[] args) {
      
        Pessoa p1 = new Pessoa();
        Endereco e1 = new Endereco("Rua A", "Cidade B", "Estado C");

        p1.setNome("Ivna Valença");
        p1.setIdade(40);
        p1.setEndereco(e1);

        System.out.println("Nome da pessoa é: " + p1.getNome());
        System.out.println("A idade da pessoa é: " + p1.getIdade() );
        System.out.println("O endereço da pessoa é: " + p1.getEndereco().getRua() + ", " + p1.getEndereco().getCidade() + ", " + p1.getEndereco().getEstado());

        Professor p = new Professor(1500, "Nome do Professor", 40, e1);
        System.out.println(p.getSalario());
        System.out.println(p.getNome());

        Aluno aluno = new Aluno("12345678");

    }
}
