package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

public class Accepted implements Freedom {
	
	@Override
	public void turnOver(Religion r)
	{
		r.setFreedom(new Accepted());
	}

}
