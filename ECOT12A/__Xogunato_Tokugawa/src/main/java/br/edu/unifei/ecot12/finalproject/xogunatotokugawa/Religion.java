package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

public abstract class Religion {
	
	private String sacredText;
	private String sacredSymbol;
	private String entityFollowed;
	private Freedom freedom = new Accepted(); //começa com Accepted por padrão na criação do objeto, sujeito a mudança de estado por sakoku
	
	public abstract Religion myClone();

	public String getSacredText() {
		return sacredText;
	}

	public void setSacredText(String sacredText) {
		this.sacredText = sacredText;
	}

	public String getSacredSymbol() {
		return sacredSymbol;
	}

	public void setSacredSymbol(String sacredSymbol) {
		this.sacredSymbol = sacredSymbol;
	}

	public String getEntityFollowed() {
		return entityFollowed;
	}

	public void setEntityFollowed(String entityFollowed) {
		this.entityFollowed = entityFollowed;
	}

	public Freedom getFreedom() {
		return freedom;
	}

	public void setFreedom(Freedom freedom) {
		this.freedom = freedom;
	}

}
