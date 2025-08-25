package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

public class Daimyo extends Edo_Society {
	
	private String clan;
	private String territory;
	private String castleName;
	
	private Constructors royalConstructors;
	private Constructors religiousConstructors;
	private Constructors botanicals;
	
	public String getClan() {
		return clan;
	}
	public void setClan(String clan) {
		this.clan = clan;
	}
	public String getTerritory() {
		return territory;
	}
	public void setTerritory(String territory) {
		this.territory = territory;
	}
	public String getCastleName() {
		return castleName;
	}
	public void setCastleName(String castleName) {
		this.castleName = castleName;
	}
	public Constructors getRoyalConstructors() {
		return royalConstructors;
	}
	public void setRoyalConstructors(Constructors royalConstructors) {
		this.royalConstructors = royalConstructors;
	}
	public Constructors getReligiousConstructors() {
		return religiousConstructors;
	}
	public void setReligiousConstructors(Constructors religiousConstructors) {
		this.religiousConstructors = religiousConstructors;
	}
	public Constructors getBotanicals() {
		return botanicals;
	}
	public void setBotanicals(Constructors botanicals) {
		this.botanicals = botanicals;
	}

	
}
