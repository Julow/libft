/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 23:33:02 by juloo             #+#    #+#             */
/*   Updated: 2015/08/23 00:59:45 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_hmap.h"
#include "ft_internal.h"
#include <stdlib.h>

t_sub const		g_test_keys[] = {
	SUBC("Lorem"), SUBC("arcu,"), SUBC("vulputate"), SUBC("cubilia"), SUBC("arcu"), SUBC("sapien"), SUBC("diam"), SUBC("laoreet"),
	SUBC("ipsum"), SUBC("et"), SUBC("mi,"), SUBC("Curae;"), SUBC("nulla,"), SUBC("maximus"), SUBC("nisl"), SUBC("nunc"),
	SUBC("dolor"), SUBC("consequat"), SUBC("nec"), SUBC("Proin"), SUBC("tristique"), SUBC("purus"), SUBC("pharetra"), SUBC("et"),
	SUBC("sit"), SUBC("urna"), SUBC("facilisis"), SUBC("rutrum"), SUBC("sit"), SUBC("ornare"), SUBC("enim,"), SUBC("dui"),
	SUBC("amet,"), SUBC("molestie"), SUBC("sem"), SUBC("erat"), SUBC("amet"), SUBC("efficitur."), SUBC("ac"), SUBC("dapibus,"),
	SUBC("consectetur"), SUBC("sed."), SUBC("sodales"), SUBC("eu"), SUBC("sodales"), SUBC("Nunc"), SUBC("auctor"), SUBC("ac"),
	SUBC("adipiscing"), SUBC("Aenean"), SUBC("vitae."), SUBC("elit"), SUBC("eu,"), SUBC("ut"), SUBC("mauris"), SUBC("semper"),
	SUBC("elit."), SUBC("feugiat"), SUBC("Suspendisse"), SUBC("elementum"), SUBC("commodo"), SUBC("venenatis"), SUBC("metus"), SUBC("lorem"),
	SUBC("In"), SUBC("sodales"), SUBC("vitae"), SUBC("interdum."), SUBC("et"), SUBC("magna."), SUBC("ut"), SUBC("ultrices."),
	SUBC("vitae"), SUBC("lacinia."), SUBC("vulputate"), SUBC("Aliquam"), SUBC("justo."), SUBC("Ut"), SUBC("elit."), SUBC("Mauris"),
	SUBC("metus"), SUBC("Integer"), SUBC("ligula,"), SUBC("non"), SUBC("Suspendisse"), SUBC("nisi"), SUBC("Morbi"), SUBC("tincidunt"),
	SUBC("ac"), SUBC("fermentum"), SUBC("et"), SUBC("ante"), SUBC("ac"), SUBC("enim,"), SUBC("cursus"), SUBC("mi"),
	SUBC("lacus"), SUBC("aliquet"), SUBC("euismod"), SUBC("ligula."), SUBC("diam"), SUBC("convallis"), SUBC("turpis"), SUBC("ipsum,"),
	SUBC("tristique"), SUBC("leo"), SUBC("purus."), SUBC("Phasellus"), SUBC("id"), SUBC("non"), SUBC("non"), SUBC("a"),
	SUBC("dictum"), SUBC("et"), SUBC("Etiam"), SUBC("at"), SUBC("ligula"), SUBC("dolor"), SUBC("metus"), SUBC("pretium"),
	SUBC("quis"), SUBC("porttitor."), SUBC("in"), SUBC("ligula"), SUBC("fringilla"), SUBC("vitae,"), SUBC("ornare"), SUBC("nisi"),
	SUBC("a"), SUBC("Ut"), SUBC("felis"), SUBC("malesuada,"), SUBC("efficitur."), SUBC("euismod"), SUBC("dignissim."), SUBC("euismod"),
	SUBC("eros."), SUBC("venenatis"), SUBC("tempor,"), SUBC("auctor"), SUBC("Integer"), SUBC("luctus"), SUBC("In"), SUBC("non."),
	SUBC("Nam"), SUBC("vulputate"), SUBC("egestas"), SUBC("turpis"), SUBC("tellus"), SUBC("elit."), SUBC("quis"), SUBC("Mauris"),
	SUBC("venenatis"), SUBC("libero"), SUBC("augue"), SUBC("vulputate,"), SUBC("nisi,"), SUBC("Sed"), SUBC("bibendum"), SUBC("sagittis"),
	SUBC("gravida"), SUBC("dapibus"), SUBC("ut,"), SUBC("interdum"), SUBC("dapibus"), SUBC("at"), SUBC("nisi,"), SUBC("gravida"),
	SUBC("mi,"), SUBC("congue."), SUBC("commodo"), SUBC("leo."), SUBC("vitae"), SUBC("augue"), SUBC("non"), SUBC("massa,"),
	SUBC("a"), SUBC("Maecenas"), SUBC("est."), SUBC("Nulla"), SUBC("tincidunt"), SUBC("enim."), SUBC("egestas"), SUBC("a"),
	SUBC("aliquam"), SUBC("at"), SUBC("Maecenas"), SUBC("convallis"), SUBC("non,"), SUBC("Maecenas"), SUBC("orci."), SUBC("commodo"),
	SUBC("est"), SUBC("ipsum"), SUBC("neque"), SUBC("odio"), SUBC("fermentum"), SUBC("ipsum"), SUBC("Interdum"), SUBC("magna"),
	SUBC("dapibus"), SUBC("ac"), SUBC("erat,"), SUBC("vitae"), SUBC("ac"), SUBC("quam,"), SUBC("et"), SUBC("rhoncus"),
	SUBC("malesuada"), SUBC("eu."), SUBC("purus"), SUBC("consequat"), SUBC("odio"), SUBC("tellus."), SUBC("laoreet"), SUBC("malesuada"), SUBC("id."),
	SUBC("fames"), SUBC("Phasellus"), SUBC("auctor"), SUBC("nec"), SUBC("imperdiet,"), SUBC("Quisque"), SUBC("vitae"), SUBC("fames"), SUBC("Nullam"),
	SUBC("ac"), SUBC("tempor"), SUBC("laoreet."), SUBC("tincidunt"), SUBC("quis"), SUBC("euismod"), SUBC("dui"), SUBC("ac"), SUBC("id"),
	SUBC("turpis"), SUBC("quam"), SUBC("Fusce"), SUBC("vitae,"), SUBC("tempor"), SUBC("varius"), SUBC("non,"), SUBC("ante"), SUBC("lorem"),
	SUBC("egestas."), SUBC("quis"), SUBC("egestas,"), SUBC("feugiat"), SUBC("nisi"), SUBC("diam"), SUBC("molestie"), SUBC("ipsum"), SUBC("eu"),
	SUBC("Curabitur"), SUBC("accumsan"), SUBC("felis"), SUBC("ut"), SUBC("sagittis."), SUBC("in"), SUBC("condimentum"), SUBC("primis"), SUBC("metus"),
	SUBC("euismod"), SUBC("suscipit."), SUBC("et"), SUBC("tellus."), SUBC("Aenean"), SUBC("iaculis."), SUBC("purus."), SUBC("in"), SUBC("egestas"),
	SUBC("quam"), SUBC("Sed"), SUBC("aliquam"), SUBC("Nullam"), SUBC("ac"), SUBC("Suspendisse"), SUBC("Aliquam"), SUBC("faucibus."), SUBC("ornare"),
	SUBC("ac"), SUBC("pretium"), SUBC("sodales,"), SUBC("eleifend"), SUBC("venenatis"), SUBC("suscipit,"), SUBC("cursus"), SUBC("Sed"), SUBC("non"),
	SUBC("porta"), SUBC("metus"), SUBC("leo"), SUBC("dui"), SUBC("metus."), SUBC("tortor"), SUBC("accumsan"), SUBC("finibus"), SUBC("eu"),
	SUBC("cursus."), SUBC("nisl,"), SUBC("est"), SUBC("sem,"), SUBC("Etiam"), SUBC("ac"), SUBC("semper."), SUBC("lectus"), SUBC("lacus.Mauris"),
	SUBC("Nullam"), SUBC("at"), SUBC("vestibulum"), SUBC("non"), SUBC("sodales"), SUBC("viverra"), SUBC("Sed"), SUBC("non"), SUBC("lacinia"),
	SUBC("commodo"), SUBC("tristique"), SUBC("ex,"), SUBC("bibendum"), SUBC("tincidunt"), SUBC("lacinia,"), SUBC("sit"), SUBC("ex"), SUBC("arcu"),
	SUBC("et"), SUBC("ipsum"), SUBC("ultricies"), SUBC("mauris"), SUBC("condimentum."), SUBC("ipsum"), SUBC("amet"), SUBC("aliquet"), SUBC("et"),
	SUBC("lectus"), SUBC("pulvinar"), SUBC("pretium"), SUBC("sollicitudin"), SUBC("Proin"), SUBC("justo"), SUBC("varius"), SUBC("posuere."), SUBC("leo"),
	SUBC("eget"), SUBC("et."), SUBC("nulla"), SUBC("sed."), SUBC("sit"), SUBC("aliquet"), SUBC("massa."), SUBC("Sed"), SUBC("commodo,"),
	SUBC("dignissim."), SUBC("Nunc"), SUBC("sapien"), SUBC("Vestibulum"), SUBC("amet"), SUBC("lorem,"), SUBC("Quisque"), SUBC("convallis"), SUBC("vel"),
	SUBC("Sed"), SUBC("vulputate"), SUBC("ac"), SUBC("id"), SUBC("faucibus"), SUBC("ac"), SUBC("scelerisque"), SUBC("orci"), SUBC("semper"),
	SUBC("ac"), SUBC("tristique"), SUBC("dui."), SUBC("quam"), SUBC("ligula,"), SUBC("elementum"), SUBC("lorem"), SUBC("nulla,"), SUBC("augue"),
	SUBC("pellentesque"), SUBC("lorem"), SUBC("Morbi"), SUBC("vel"), SUBC("nec"), SUBC("diam"), SUBC("ac"), SUBC("hendrerit"), SUBC("semper."),
	SUBC("magna.Maecenas"), SUBC("ac"), SUBC("augue"), SUBC("risus"), SUBC("lobortis"), SUBC("tortor"), SUBC("fermentum"), SUBC("hendrerit"), SUBC("In"),
	SUBC("lacinia"), SUBC("malesuada."), SUBC("magna,"), SUBC("tempus"), SUBC("metus."), SUBC("at"), SUBC("euismod.Duis"), SUBC("magna"), SUBC("tellus"),
	SUBC("cursus"), SUBC("Sed"), SUBC("posuere"), SUBC("blandit"), SUBC("Donec"), SUBC("erat."), SUBC("at"), SUBC("mollis"), SUBC("velit,"),
	SUBC("magna"), SUBC("ut"), SUBC("sit"), SUBC("sit"), SUBC("ultrices"), SUBC("Aliquam"), SUBC("feugiat"), SUBC("sit"), SUBC("gravida"),
	SUBC("consequat"), SUBC("sem"), SUBC("amet"), SUBC("amet"), SUBC("augue"), SUBC("sit"), SUBC("dui."), SUBC("amet."), SUBC("quis"),
	SUBC("efficitur."), SUBC("sagittis,"), SUBC("nulla"), SUBC("vel"), SUBC("a"), SUBC("amet"), SUBC("Suspendisse"), SUBC("Proin"), SUBC("vehicula"),
	SUBC("Curabitur"), SUBC("condimentum"), SUBC("eu,"), SUBC("tortor."), SUBC("justo"), SUBC("est"), SUBC("sit"), SUBC("egestas"), SUBC("nec,"),
	SUBC("fringilla"), SUBC("augue"), SUBC("placerat"), SUBC("Nulla"), SUBC("iaculis"), SUBC("convallis"), SUBC("amet"), SUBC("ultricies"), SUBC("sollicitudin"),
	SUBC("iaculis"), SUBC("sit"), SUBC("ullamcorper"), SUBC("sollicitudin"), SUBC("congue."), SUBC("arcu"), SUBC("tortor"), SUBC("arcu.Aenean"), SUBC("congue"),
	SUBC("ex."), SUBC("amet,"), SUBC("dolor."), SUBC("ex"), SUBC("Aliquam"), SUBC("pellentesque"), SUBC("quis"), SUBC("vel"), SUBC("justo."),
	SUBC("Praesent"), SUBC("condimentum"), SUBC("Vestibulum"), SUBC("quis"), SUBC("scelerisque"), SUBC("vulputate"), SUBC("diam"), SUBC("nulla"), SUBC("Sed"),
	SUBC("vehicula"), SUBC("sapien."), SUBC("nec"), SUBC("elit"), SUBC("ut"), SUBC("vitae"), SUBC("tincidunt"), SUBC("eleifend,"), SUBC("vitae"),
	SUBC("odio"), SUBC("Nam"), SUBC("vehicula"), SUBC("facilisis,"), SUBC("quam"), SUBC("sit"), SUBC("porttitor"), SUBC("venenatis"), SUBC("aliquet"),
	SUBC("non"), SUBC("tempus"), SUBC("erat."), SUBC("eget"), SUBC("et"), SUBC("amet"), SUBC("in"), SUBC("nisi"), SUBC("magna."),
	SUBC("est"), SUBC("facilisis"), SUBC("Sed"), SUBC("fermentum"), SUBC("vehicula."), SUBC("mi."), SUBC("at"), SUBC("a,"), SUBC("Vivamus"),
	SUBC("pulvinar,"), SUBC("pretium."), SUBC("laoreet"), SUBC("ante"), SUBC("Morbi"), SUBC("Donec"), SUBC("ligula."), SUBC("tincidunt"), SUBC("tortor"),
	SUBC("eget"), SUBC("Nullam"), SUBC("risus"), SUBC("gravida."), SUBC("consectetur"), SUBC("venenatis"), SUBC("Ut"), SUBC("arcu."), SUBC("ante,"),
	SUBC("pellentesque"), SUBC("lorem"), SUBC("et"), SUBC("Pellentesque"), SUBC("purus"), SUBC("urna"), SUBC("tincidunt"), SUBC("Vivamus"), SUBC("finibus"),
	SUBC("metus"), SUBC("neque,"), SUBC("lacus"), SUBC("nec"), SUBC("a"), SUBC("sed"), SUBC("convallis"), SUBC("non"), SUBC("non"),
	SUBC("ultricies."), SUBC("faucibus"), SUBC("placerat,"), SUBC("bibendum"), SUBC("libero"), SUBC("tortor"), SUBC("eros."), SUBC("elit"), SUBC("blandit"),
	SUBC("Cras"), SUBC("fringilla"), SUBC("eget"), SUBC("leo."), SUBC("tempus,"), SUBC("pretium"), SUBC("Quisque"), SUBC("at"), SUBC("vitae,"),
	SUBC("quam"), SUBC("ullamcorper"), SUBC("ultricies"), SUBC("Duis"), SUBC("id"), SUBC("luctus."), SUBC("aliquam"), SUBC("arcu"), SUBC("tempor"),
	SUBC("purus,"), SUBC("eget,"), SUBC("nulla"), SUBC("faucibus"), SUBC("blandit"), SUBC("Nulla"), SUBC("commodo"), SUBC("condimentum"), SUBC("ac"),
	SUBC("ullamcorper"), SUBC("vehicula"), SUBC("porttitor.Nullam"), SUBC("orci"), SUBC("ipsum"), SUBC("sapien"), SUBC("diam"), SUBC("efficitur"), SUBC("magna."),
	SUBC("vel"), SUBC("a"), SUBC("dictum"), SUBC("ut"), SUBC("luctus."), SUBC("nisl,"), SUBC("eget"), SUBC("eget"), SUBC("Integer"),
	SUBC("commodo"), SUBC("mauris."), SUBC("ultrices"), SUBC("nisi"), SUBC("Suspendisse"), SUBC("pharetra"), SUBC("congue."), SUBC("et"), SUBC("mattis"),
	SUBC("posuere,"), SUBC("Integer"), SUBC("quam"), SUBC("convallis"), SUBC("vulputate"), SUBC("tempus"), SUBC("Lorem"), SUBC("eros."), SUBC("accumsan"),
	SUBC("euismod"), SUBC("vestibulum"), SUBC("vel"), SUBC("sagittis."), SUBC("eleifend"), SUBC("dui"), SUBC("ipsum"), SUBC("Mauris"), SUBC("sem"),
	SUBC("vel"), SUBC("placerat"), SUBC("tempor."), SUBC("Mauris"), SUBC("felis,"), SUBC("non,"), SUBC("dolor"), SUBC("et"), SUBC("et"),
	SUBC("purus."), SUBC("mi,"), SUBC("Quisque"), SUBC("sed"), SUBC("at"), SUBC("facilisis"), SUBC("sit"), SUBC("posuere"), SUBC("maximus."),
	SUBC("Aliquam"), SUBC("et"), SUBC("scelerisque"), SUBC("lacus"), SUBC("pretium"), SUBC("pharetra"), SUBC("amet,"), SUBC("velit,"), SUBC("Nullam"),
	SUBC("vel"), SUBC("pharetra"), SUBC("fringilla"), SUBC("in"), SUBC("sapien"), SUBC("ante."), SUBC("consectetur"), SUBC("in"), SUBC("ut"),
	SUBC("convallis"), SUBC("felis"), SUBC("tellus,"), SUBC("lectus"), SUBC("lacinia"), SUBC("Curabitur"), SUBC("adipiscing"), SUBC("accumsan"), SUBC("quam"),
	SUBC("sem."), SUBC("ultrices"), SUBC("lacinia"), SUBC("elementum"), SUBC("id.Sed"), SUBC("in"), SUBC("elit."), SUBC("neque."), SUBC("vestibulum,"),
	SUBC("Sed"), SUBC("et.In"), SUBC("fringilla"), SUBC("luctus"), SUBC("sagittis"), SUBC("rutrum"), SUBC("Donec"), SUBC("Curabitur"), SUBC("placerat"),
	SUBC("auctor"), SUBC("auctor"), SUBC("elit"), SUBC("sed"), SUBC("elementum"), SUBC("libero,"), SUBC("non"), SUBC("ultrices"), SUBC("erat"),
	SUBC("pellentesque"), SUBC("felis"), SUBC("mattis"), SUBC("ut"), SUBC("malesuada."), SUBC("tempus"), SUBC("lectus"), SUBC("placerat"), SUBC("ac,"),
	SUBC("posuere."), SUBC("ac"), SUBC("vitae."), SUBC("mi.Etiam"), SUBC("Nam"), SUBC("rhoncus"), SUBC("nunc."), SUBC("vestibulum."), SUBC("rutrum"),
	SUBC("Aenean"), SUBC("nisi"), SUBC("Nunc"), SUBC("aliquet"), SUBC("condimentum,"), SUBC("ex."), SUBC("Proin"), SUBC("Curabitur"), SUBC("ipsum."),
	SUBC("non"), SUBC("finibus,"), SUBC("felis"), SUBC("euismod"), SUBC("augue"), SUBC("Etiam"), SUBC("nec"), SUBC("libero"), SUBC("Mauris"),
	SUBC("ornare"), SUBC("nec"), SUBC("urna,"), SUBC("lorem"), SUBC("in"), SUBC("ultricies"), SUBC("eros"), SUBC("turpis,"), SUBC("blandit"),
	SUBC("nunc,"), SUBC("placerat"), SUBC("sagittis"), SUBC("vel"), SUBC("pulvinar"), SUBC("consectetur"), SUBC("at"), SUBC("pretium"), SUBC("mi"),
	SUBC("vel"), SUBC("augue"), SUBC("sed"), SUBC("hendrerit."), SUBC("molestie,"), SUBC("eros,"), SUBC("ex"), SUBC("sit"), SUBC("vel"),
	SUBC("cursus"), SUBC("iaculis."), SUBC("tortor"), SUBC("Vestibulum"), SUBC("sem"), SUBC("sit"), SUBC("volutpat"), SUBC("amet"), SUBC("lacus"),
	SUBC("nisl."), SUBC("Cras"), SUBC("at,"), SUBC("ante"), SUBC("dui"), SUBC("amet"), SUBC("accumsan"), SUBC("sem"), SUBC("dictum"),
	SUBC("Maecenas"), SUBC("vitae"), SUBC("faucibus"), SUBC("ipsum"), SUBC("volutpat"), SUBC("aliquet"), SUBC("et"), SUBC("in,"), SUBC("placerat."),
	SUBC("volutpat"), SUBC("nunc"), SUBC("auctor"), SUBC("primis"), SUBC("eros,"), SUBC("ligula"), SUBC("quis"), SUBC("vehicula"), SUBC("Pellentesque"),
	SUBC("ultrices"), SUBC("porta"), SUBC("turpis."), SUBC("in"), SUBC("et"), SUBC("scelerisque"), SUBC("ipsum."), SUBC("ullamcorper"), SUBC("habitant"),
	SUBC("ipsum,"), SUBC("nisi"), SUBC("In"), SUBC("faucibus"), SUBC("sollicitudin"), SUBC("in."), SUBC("Etiam"), SUBC("lorem."), SUBC("morbi"),
	SUBC("fermentum"), SUBC("lobortis"), SUBC("luctus"), SUBC("orci"), SUBC("lorem"), SUBC("Aliquam"), SUBC("placerat,"), SUBC("Fusce"), SUBC("tristique"),
	SUBC("malesuada"), SUBC("posuere."), SUBC("aliquet"), SUBC("luctus"), SUBC("sem"), SUBC("vel"), SUBC("nulla"), SUBC("fringilla"), SUBC("senectus"),
	SUBC("urna"), SUBC("Duis"), SUBC("accumsan."), SUBC("et"), SUBC("maximus"), SUBC("varius"), SUBC("ac"), SUBC("pretium"), SUBC("et"),
	SUBC("lobortis"), SUBC("auctor"), SUBC("Proin"), SUBC("ultrices"), SUBC("augue."), SUBC("tellus.Ut"), SUBC("mattis"), SUBC("porttitor."), SUBC("netus"),
	SUBC("vel."), SUBC("accumsan"), SUBC("varius"), SUBC("posuere"), SUBC("Morbi"), SUBC("et"), SUBC("facilisis,"), SUBC("Donec"), SUBC("et"),
	SUBC("curvy"), SUBC("sink"), SUBC("bit"), SUBC("sisters"), SUBC("excellent"), SUBC("dare"), SUBC("wood"), SUBC("aboard"), SUBC("screeching"), SUBC("pen"), SUBC("copper"), SUBC("venomous"), SUBC("pull"), SUBC("touch"), SUBC("exercise"), SUBC("manage"), SUBC("open"), SUBC("versed"), SUBC("abundant"), SUBC("confused"), SUBC("eyes"), SUBC("tendency"), SUBC("hope"), SUBC("few"), SUBC("record"), SUBC("whip"), SUBC("juice"), SUBC("likeable"), SUBC("rebel"), SUBC("gruesome"),
	SUBC("flashy"), SUBC("bitter"), SUBC("babies"), SUBC("trip"), SUBC("rings"), SUBC("tranquil"), SUBC("damage"), SUBC("brainy"), SUBC("mom"), SUBC("suppose"), SUBC("stitch"), SUBC("fretful"), SUBC("violet"), SUBC("uninterested"), SUBC("advice"), SUBC("bath"), SUBC("luxuriant"), SUBC("ablaze"), SUBC("dinosaurs"), SUBC("handsomely"), SUBC("dirt"), SUBC("poor"), SUBC("wobble"), SUBC("question"), SUBC("waggish"), SUBC("smash"), SUBC("crack"), SUBC("trees"), SUBC("adhesive"), SUBC("gaudy"),
	SUBC("curve"), SUBC("stereotyped"), SUBC("pancake"), SUBC("practise"), SUBC("guide"), SUBC("enchanted"), SUBC("middle"), SUBC("crowded"), SUBC("ski"), SUBC("walk"), SUBC("duck"), SUBC("berry"), SUBC("inform"), SUBC("like"), SUBC("nice"), SUBC("complain"), SUBC("tax"), SUBC("matter"), SUBC("trust"), SUBC("fairies"), SUBC("fish"), SUBC("sand"), SUBC("exchange"), SUBC("lonely"), SUBC("coal"), SUBC("open"), SUBC("protective"), SUBC("sheep"), SUBC("fierce"), SUBC("nosy"),
	SUBC("poke"), SUBC("rescue"), SUBC("humdrum"), SUBC("upset"), SUBC("increase"), SUBC("functional"), SUBC("air"), SUBC("kneel"), SUBC("record"), SUBC("remember"), SUBC("discreet"), SUBC("sleet"), SUBC("supply"), SUBC("friends"), SUBC("stew"), SUBC("home"), SUBC("lake"), SUBC("lick"), SUBC("hurt"), SUBC("ugly"), SUBC("calculate"), SUBC("inject"), SUBC("dress"), SUBC("work"), SUBC("puzzling"), SUBC("nail"), SUBC("match"), SUBC("plot"), SUBC("fair"), SUBC("doubtful"),
	SUBC("interest"), SUBC("needy"), SUBC("memory"), SUBC("tired"), SUBC("tease"), SUBC("paste"), SUBC("dapper"), SUBC("innocent"), SUBC("bizarre"), SUBC("actually"), SUBC("unique"), SUBC("glue"), SUBC("important"), SUBC("baseball"), SUBC("mammoth"), SUBC("tumble"), SUBC("psychedelic"), SUBC("clam"), SUBC("handsome"), SUBC("ship"), SUBC("station"), SUBC("graceful"), SUBC("nest"), SUBC("forgetful"), SUBC("blood"), SUBC("relax"), SUBC("peace"), SUBC("toothsome"), SUBC("uppity"), SUBC("soda"),
	SUBC("expect"), SUBC("green"), SUBC("x-ray"), SUBC("slave"), SUBC("rigid"), SUBC("furry"), SUBC("spotty"), SUBC("dust"), SUBC("unsuitable"), SUBC("person"), SUBC("kill"), SUBC("improve"), SUBC("place"), SUBC("thinkable"), SUBC("rely"), SUBC("team"), SUBC("juicy"), SUBC("half"), SUBC("uneven"), SUBC("quiver"), SUBC("unruly"), SUBC("grouchy"), SUBC("ducks"), SUBC("worthless"), SUBC("available"), SUBC("fold"), SUBC("verdant"), SUBC("agonizing"), SUBC("embarrassed"), SUBC("spotted"),
	SUBC("quixotic"), SUBC("agree"), SUBC("rest"), SUBC("arithmetic"), SUBC("dry"), SUBC("arm"), SUBC("birthday"), SUBC("memorise"), SUBC("level"), SUBC("womanly"), SUBC("stingy"), SUBC("feigned"), SUBC("argue"), SUBC("trail"), SUBC("sparkling"), SUBC("guarded"), SUBC("marked"), SUBC("pollution"), SUBC("well-to-do"), SUBC("smiling"), SUBC("gifted"), SUBC("whip"), SUBC("creature"), SUBC("sign"), SUBC("notice"), SUBC("sign"), SUBC("rustic"), SUBC("van"), SUBC("big"), SUBC("reward"),
	SUBC("quizzical"), SUBC("smoggy"), SUBC("iron"), SUBC("punishment"), SUBC("piquant"), SUBC("unpack"), SUBC("structure"), SUBC("compare"), SUBC("driving"), SUBC("wild"), SUBC("cow"), SUBC("new"), SUBC("occur"), SUBC("therapeutic"), SUBC("horse"), SUBC("supreme"), SUBC("wandering"), SUBC("throne"), SUBC("teaching"), SUBC("curly"), SUBC("bathe"), SUBC("previous"), SUBC("cultured"), SUBC("tremendous"), SUBC("private"), SUBC("redundant"), SUBC("vest"), SUBC("alluring"), SUBC("acoustic"), SUBC("peck"),
	SUBC("twig"), SUBC("fanatical"), SUBC("decision"), SUBC("huge"), SUBC("shut"), SUBC("suck"), SUBC("chess"), SUBC("pets"), SUBC("beneficial"), SUBC("trade"), SUBC("stiff"), SUBC("curtain"), SUBC("country"), SUBC("linen"), SUBC("able"), SUBC("spiritual"), SUBC("measure"), SUBC("frail"), SUBC("instinctive"), SUBC("fear"), SUBC("mug"), SUBC("lumpy"), SUBC("women"), SUBC("part"), SUBC("haircut"), SUBC("surprise"), SUBC("morning"), SUBC("trite"), SUBC("join"), SUBC("rub"),
	SUBC("unequaled"), SUBC("lip"), SUBC("confuse"), SUBC("cynical"), SUBC("hug"), SUBC("flood"), SUBC("shock"), SUBC("future"), SUBC("plain"), SUBC("suit"), SUBC("panicky"), SUBC("relieved"), SUBC("quill"), SUBC("wakeful"), SUBC("appreciate"), SUBC("murky"), SUBC("third"), SUBC("waste"), SUBC("branch"), SUBC("condemned"), SUBC("decay"), SUBC("excited"), SUBC("shrug"), SUBC("bushes"), SUBC("fly"), SUBC("test"), SUBC("righteous"), SUBC("wary"), SUBC("top"), SUBC("dreary"),
	SUBC("reading"), SUBC("scientific"), SUBC("clover"), SUBC("title"), SUBC("grubby"), SUBC("dress"), SUBC("bewildered"), SUBC("quince"), SUBC("thirsty"), SUBC("size"), SUBC("books"), SUBC("terrible"), SUBC("giddy"), SUBC("simplistic"), SUBC("keen"), SUBC("tip"), SUBC("naughty"), SUBC("overrated"), SUBC("decisive"), SUBC("help"), SUBC("cry"), SUBC("kindly"), SUBC("glossy"), SUBC("head"), SUBC("shelf"), SUBC("sneaky"), SUBC("aquatic"), SUBC("telephone"), SUBC("tough"), SUBC("milky"),
	SUBC("eggnog"), SUBC("representative"), SUBC("daughter"), SUBC("hushed"), SUBC("connection"), SUBC("invincible"), SUBC("delay"), SUBC("lively"), SUBC("deep"), SUBC("parsimonious"), SUBC("common"), SUBC("grease"), SUBC("fear"), SUBC("nut"), SUBC("plan"), SUBC("cart"), SUBC("thoughtless"), SUBC("edge"), SUBC("grass"), SUBC("rhythm"), SUBC("fat"), SUBC("incandescent"), SUBC("destroy"), SUBC("hydrant"), SUBC("different"), SUBC("trick"), SUBC("plants"), SUBC("houses"), SUBC("secretary"), SUBC("delicious"),
	SUBC("suggest"), SUBC("faint"), SUBC("behavior"), SUBC("chicken"), SUBC("chief"), SUBC("kiss"), SUBC("smart"), SUBC("care"), SUBC("whirl"), SUBC("current"), SUBC("income"), SUBC("nervous"), SUBC("drip"), SUBC("wash"), SUBC("car"), SUBC("sky"), SUBC("place"), SUBC("obtain"), SUBC("burly"), SUBC("water"), SUBC("men"), SUBC("bounce"), SUBC("learn"), SUBC("crime"), SUBC("wine"), SUBC("frame"), SUBC("toys"), SUBC("adventurous"), SUBC("high-pitched"), SUBC("stranger"),
	SUBC("absorbed"), SUBC("lunchroom"), SUBC("whine"), SUBC("optimal"), SUBC("peel"), SUBC("day"), SUBC("bell"), SUBC("train"), SUBC("acid"), SUBC("hospital"), SUBC("unbiased"), SUBC("name"), SUBC("juvenile"), SUBC("button"), SUBC("good"), SUBC("hose"), SUBC("mine"), SUBC("challenge"), SUBC("military"), SUBC("impartial"), SUBC("cough"), SUBC("efficient"), SUBC("wet"), SUBC("petite"), SUBC("book"), SUBC("reproduce"), SUBC("smile"), SUBC("crack"), SUBC("untidy"), SUBC("joke"),
	SUBC("skirt"), SUBC("imperfect"), SUBC("terrific"), SUBC("pig"), SUBC("plastic"), SUBC("ill-informed"), SUBC("coil"), SUBC("lazy"), SUBC("sad"), SUBC("offend"), SUBC("quack"), SUBC("reflective"), SUBC("malicious"), SUBC("juggle"), SUBC("bury"), SUBC("tempt"), SUBC("testy"), SUBC("numberless"), SUBC("thoughtful"), SUBC("threatening"), SUBC("bulb"), SUBC("cause"), SUBC("chase"), SUBC("careless"), SUBC("muscle"), SUBC("meal"), SUBC("trot"), SUBC("nebulous"), SUBC("staking"), SUBC("awful"),
	SUBC("clear"), SUBC("laborer"), SUBC("route"), SUBC("knee"), SUBC("spoon"), SUBC("note"), SUBC("admire"), SUBC("advise"), SUBC("finicky"), SUBC("cows"), SUBC("nostalgic"), SUBC("null"), SUBC("super"), SUBC("film"), SUBC("yawn"), SUBC("snobbish"), SUBC("daily"), SUBC("muddled"), SUBC("moaning"), SUBC("black"), SUBC("coordinated"), SUBC("grateful"), SUBC("yarn"), SUBC("boy"), SUBC("embarrass"), SUBC("tan"), SUBC("joyous"), SUBC("phone"), SUBC("laughable"), SUBC("woebegone"),
	SUBC("ad"), SUBC("hoc"), SUBC("retire"), SUBC("pathetic"), SUBC("nine"), SUBC("flag"), SUBC("dust"), SUBC("untidy"), SUBC("right"), SUBC("eye"), SUBC("gather"), SUBC("bubble"), SUBC("noise"), SUBC("obese"), SUBC("lean"), SUBC("wipe"), SUBC("pest"), SUBC("cure"), SUBC("argument"), SUBC("bedroom"), SUBC("whistle"), SUBC("plant"), SUBC("substance"), SUBC("point"), SUBC("clammy"), SUBC("pizzas"), SUBC("brake"), SUBC("zonked"), SUBC("object"), SUBC("kaput"),
	SUBC("classy"), SUBC("barbarous"), SUBC("spurious"), SUBC("enormous"), SUBC("stormy"), SUBC("imported"), SUBC("polish"), SUBC("friendly"), SUBC("rhyme"), SUBC("brother"), SUBC("filthy"), SUBC("aberrant"), SUBC("regular"), SUBC("passenger"), SUBC("didactic"), SUBC("pink"), SUBC("breathe"), SUBC("frighten"), SUBC("shoes"), SUBC("neck"), SUBC("pricey"), SUBC("cluttered"), SUBC("flavor"), SUBC("company"), SUBC("equable"), SUBC("cooperative"), SUBC("separate"), SUBC("resonant"), SUBC("floor"), SUBC("extra-large"),
	SUBC("scratch"), SUBC("hook"), SUBC("male"), SUBC("volatile"), SUBC("dysfunctional"), SUBC("soggy"), SUBC("grey"), SUBC("heavenly"), SUBC("elated"), SUBC("thick"), SUBC("quaint"), SUBC("playground"), SUBC("ambiguous"), SUBC("slow"), SUBC("curl"), SUBC("coach"), SUBC("shiver"), SUBC("prickly"), SUBC("spotless"), SUBC("hand"), SUBC("crate"), SUBC("bouncy"), SUBC("reflect"), SUBC("entertain"), SUBC("foamy"), SUBC("feeble"), SUBC("highfalutin"), SUBC("thank"), SUBC("ready"), SUBC("hat"),
	SUBC("veil"), SUBC("sweater"), SUBC("abrupt"), SUBC("amuse"), SUBC("boorish"), SUBC("ajar"), SUBC("building"), SUBC("numerous"), SUBC("distance"), SUBC("please"), SUBC("cushion"), SUBC("pretty"), SUBC("minute"), SUBC("divide"), SUBC("farm"), SUBC("brash"), SUBC("bored"), SUBC("beds"), SUBC("apparatus"), SUBC("realise"), SUBC("view"), SUBC("suit"), SUBC("crazy"), SUBC("reply"), SUBC("disappear"), SUBC("skinny"), SUBC("sloppy"), SUBC("order"), SUBC("shocking"), SUBC("ritzy"),
	SUBC("torpid"), SUBC("geese"), SUBC("brass"), SUBC("scold"), SUBC("coat"), SUBC("remind"), SUBC("wind"), SUBC("angle"), SUBC("cannon"), SUBC("horn"), SUBC("evanescent"), SUBC("front"), SUBC("parallel"), SUBC("servant"), SUBC("zebra"), SUBC("dark"), SUBC("tasteless"), SUBC("harass"), SUBC("knowledge"), SUBC("acoustics"), SUBC("impulse"), SUBC("dirty"), SUBC("bump"), SUBC("disgusting"), SUBC("cloistered"), SUBC("incompetent"), SUBC("point"), SUBC("lying"), SUBC("jittery"), SUBC("superb"),
	SUBC("oranges"), SUBC("living"), SUBC("appear"), SUBC("play"), SUBC("onerous"), SUBC("elderly"), SUBC("fang"), SUBC("hum"), SUBC("enjoy"), SUBC("identify"), SUBC("slope"), SUBC("underwear"), SUBC("jar"), SUBC("wish"), SUBC("truthful"), SUBC("boundless"), SUBC("year"), SUBC("futuristic"), SUBC("unbecoming"), SUBC("walk"), SUBC("bite"), SUBC("vacation"), SUBC("boat"), SUBC("cheap"), SUBC("bake"), SUBC("flawless"), SUBC("present"), SUBC("obtainable"), SUBC("spill"), SUBC("sister"),
	SUBC("accurate"), SUBC("abashed"), SUBC("taboo"), SUBC("fork"), SUBC("rush"), SUBC("robin"), SUBC("rightful"), SUBC("curve"), SUBC("happen"), SUBC("boiling"), SUBC("tender"), SUBC("known"), SUBC("outgoing"), SUBC("pushy"), SUBC("cover"), SUBC("guide"), SUBC("imminent"), SUBC("sable"), SUBC("grip"), SUBC("ghost"), SUBC("illegal"), SUBC("pointless"), SUBC("pray"), SUBC("complete"), SUBC("icicle"), SUBC("puzzled"), SUBC("smooth"), SUBC("instrument"), SUBC("naive"), SUBC("dance"),
	SUBC("pear"), SUBC("flowery"), SUBC("oven"), SUBC("earsplitting"), SUBC("dream"), SUBC("town"), SUBC("honey"), SUBC("wash"), SUBC("sedate"), SUBC("creator"), SUBC("obey"), SUBC("scare"), SUBC("dolls"), SUBC("blot"), SUBC("industrious"), SUBC("attack"), SUBC("hand"), SUBC("head"), SUBC("comparison"), SUBC("hard"), SUBC("carry"), SUBC("low"), SUBC("stare"), SUBC("dear"), SUBC("fearless"), SUBC("weather"), SUBC("shrill"), SUBC("merciful"), SUBC("many"), SUBC("rambunctious"),
	SUBC("health"), SUBC("fill"), SUBC("range"), SUBC("chin"), SUBC("discussion"), SUBC("animal"), SUBC("furtive"), SUBC("deranged"), SUBC("ossified"), SUBC("hope"), SUBC("kick"), SUBC("stove"), SUBC("chalk"), SUBC("draconian"), SUBC("madly"), SUBC("name"), SUBC("cup"), SUBC("owe"), SUBC("store"), SUBC("vacuous"), SUBC("elite"), SUBC("squeak"), SUBC("brush"), SUBC("zealous"), SUBC("level"), SUBC("same"), SUBC("lewd"), SUBC("fancy"), SUBC("true"), SUBC("pumped"),
	SUBC("acrid"), SUBC("precede"), SUBC("languid"), SUBC("airplane"), SUBC("push"), SUBC("watery"), SUBC("tall"), SUBC("cooing"), SUBC("flap"), SUBC("soap"), SUBC("stamp"), SUBC("overconfident"), SUBC("special"), SUBC("frightened"), SUBC("bear"), SUBC("deceive"), SUBC("knife"), SUBC("visit"), SUBC("capricious"), SUBC("rat"), SUBC("zany"), SUBC("prefer"), SUBC("moon"), SUBC("rifle"), SUBC("spark"), SUBC("mess"), SUBC("up"), SUBC("plastic"), SUBC("childlike"), SUBC("rude"),
	SUBC("crash"), SUBC("sick"), SUBC("dime"), SUBC("ultra"), SUBC("cause"), SUBC("slim"), SUBC("aggressive"), SUBC("hate"), SUBC("abounding"), SUBC("funny"), SUBC("scissors"), SUBC("string"), SUBC("nimble"), SUBC("depressed"), SUBC("combative"), SUBC("fold"), SUBC("historical"), SUBC("peep"), SUBC("slip"), SUBC("bent"), SUBC("teeny-tiny"), SUBC("late"), SUBC("snatch"), SUBC("parched"), SUBC("squalid"), SUBC("plate"), SUBC("notebook"), SUBC("level"), SUBC("vivacious"), SUBC("kindhearted"),
	SUBC("crown"), SUBC("check"), SUBC("plausible"), SUBC("rake"), SUBC("intelligent"), SUBC("stream"), SUBC("library"), SUBC("zinc"), SUBC("hollow"), SUBC("zesty"), SUBC("adjustment"), SUBC("zippy"), SUBC("second"), SUBC("left"), SUBC("tangible"), SUBC("admit"), SUBC("somber"), SUBC("exclusive"), SUBC("share"), SUBC("face"), SUBC("waves"), SUBC("vanish"), SUBC("strange"), SUBC("grade"), SUBC("existence"), SUBC("flock"), SUBC("charge"), SUBC("squirrel"), SUBC("pleasant"), SUBC("material"),
	SUBC("exist"), SUBC("creepy"), SUBC("helpful"), SUBC("slip"), SUBC("grotesque"), SUBC("moor"), SUBC("ratty"), SUBC("diligent"), SUBC("dock"), SUBC("envious"), SUBC("decide"), SUBC("longing"), SUBC("tacky"), SUBC("time"), SUBC("gaze"), SUBC("type"), SUBC("event"), SUBC("nondescript"), SUBC("ground"), SUBC("wren"), SUBC("decorous"), SUBC("cloudy"), SUBC("blue-eyed"), SUBC("gigantic"), SUBC("serious"), SUBC("loaf"), SUBC("window"), SUBC("prevent"), SUBC("hall"), SUBC("free"),
	SUBC("yummy"), SUBC("drain"), SUBC("certain"), SUBC("steel"), SUBC("disarm"), SUBC("daffy"), SUBC("average"), SUBC("mature"), SUBC("spy"), SUBC("furniture"), SUBC("habitual"), SUBC("time"), SUBC("nose"), SUBC("steady"), SUBC("gamy"), SUBC("suspect"), SUBC("fowl"), SUBC("excite"), SUBC("ice"), SUBC("better"), SUBC("meat"), SUBC("utter"), SUBC("ten"), SUBC("bleach"), SUBC("well-made"), SUBC("hate"), SUBC("food"), SUBC("earn"), SUBC("relation"), SUBC("drown"),
	SUBC("stir"), SUBC("harbor"), SUBC("alike"), SUBC("wooden"), SUBC("adjoining"), SUBC("scared"), SUBC("sprout"), SUBC("camera"), SUBC("end"), SUBC("stain"), SUBC("grate"), SUBC("endurable"), SUBC("penitent"), SUBC("shame"), SUBC("pull"), SUBC("peaceful"), SUBC("expert"), SUBC("milk"), SUBC("stimulating"), SUBC("flesh"), SUBC("arrange"), SUBC("frame"), SUBC("loutish"), SUBC("waste"), SUBC("nasty"), SUBC("yellow"), SUBC("mend"), SUBC("snotty"), SUBC("use"), SUBC("drab"),
	SUBC("early"), SUBC("shelter"), SUBC("secretive"), SUBC("hour"), SUBC("develop"), SUBC("complete"), SUBC("abnormal"), SUBC("pocket"), SUBC("stuff"), SUBC("belligerent"), SUBC("recess"), SUBC("striped"), SUBC("sore"), SUBC("lame"), SUBC("sack"), SUBC("mute"), SUBC("fascinated"), SUBC("troubled"), SUBC("fancy"), SUBC("bright"), SUBC("abrasive"), SUBC("humorous"), SUBC("ahead"), SUBC("smile"), SUBC("disturbed"), SUBC("loving"), SUBC("useful"), SUBC("baby"), SUBC("power"), SUBC("full"),
	SUBC("wire"), SUBC("rot"), SUBC("one"), SUBC("irritating"), SUBC("reign"), SUBC("aboriginal"), SUBC("own"), SUBC("tank"), SUBC("gorgeous"), SUBC("sense"), SUBC("scrub"), SUBC("political"), SUBC("grin"), SUBC("wrench"), SUBC("uttermost"), SUBC("neat"), SUBC("slap"), SUBC("hungry"), SUBC("fruit"), SUBC("ear"), SUBC("silky"), SUBC("powder"), SUBC("interesting"), SUBC("return"), SUBC("jumpy"), SUBC("selective"), SUBC("road"), SUBC("seal"), SUBC("self"), SUBC("opposite"),
	SUBC("fasten"), SUBC("stamp"), SUBC("homely"), SUBC("visitor"), SUBC("mouth"), SUBC("changeable"), SUBC("property"), SUBC("songs"), SUBC("alive"), SUBC("committee"), SUBC("chilly"), SUBC("best"), SUBC("mice"), SUBC("noiseless"), SUBC("slow"), SUBC("annoy"), SUBC("load"), SUBC("pause"), SUBC("silly"), SUBC("magnificent"), SUBC("planes"), SUBC("yell"), SUBC("jeans"), SUBC("butter"), SUBC("shock"), SUBC("delirious"), SUBC("assorted"), SUBC("step"), SUBC("scarce"), SUBC("sturdy"),
	SUBC("oafish"), SUBC("decorate"), SUBC("idea"), SUBC("whistle"), SUBC("store"), SUBC("trouble"), SUBC("magenta"), SUBC("fabulous"), SUBC("radiate"), SUBC("exciting"), SUBC("majestic"), SUBC("cuddly"), SUBC("snail"), SUBC("bumpy"), SUBC("locket"), SUBC("tearful"), SUBC("surprise"), SUBC("spiders"), SUBC("recognise"), SUBC("bomb"), SUBC("tickle"), SUBC("value"), SUBC("unhealthy"), SUBC("skate"), SUBC("succeed"), SUBC("stupendous"), SUBC("judge"), SUBC("rule"), SUBC("mark"), SUBC("cool"),
	SUBC("regret"), SUBC("river"), SUBC("son"), SUBC("elegant"), SUBC("dizzy"), SUBC("truck"), SUBC("sour"), SUBC("holiday"), SUBC("mundane"), SUBC("irate"), SUBC("disagree"), SUBC("hurry"), SUBC("giant"), SUBC("sail"), SUBC("hobbies"), SUBC("comfortable"), SUBC("cough"), SUBC("outrageous"), SUBC("selfish"), SUBC("maddening"), SUBC("cherry"), SUBC("energetic"), SUBC("talented"), SUBC("communicate"), SUBC("program"), SUBC("sleepy"), SUBC("park"), SUBC("call"), SUBC("violent"), SUBC("suffer"),
	SUBC("broken"), SUBC("shade"), SUBC("caption"), SUBC("satisfying"), SUBC("night"), SUBC("bag"), SUBC("trace"), SUBC("infamous"), SUBC("drawer"), SUBC("birth"), SUBC("society"), SUBC("water"), SUBC("wise"), SUBC("noxious"), SUBC("unaccountable"), SUBC("warm"), SUBC("spiffy"), SUBC("quick"), SUBC("kiss"), SUBC("bait"), SUBC("shake"), SUBC("thrill"), SUBC("fortunate"), SUBC("disgusted"), SUBC("sun"), SUBC("exuberant"), SUBC("camp"), SUBC("solid"), SUBC("careful"), SUBC("sparkle"),
	SUBC("protest"), SUBC("burst"), SUBC("automatic"), SUBC("bang"), SUBC("hellish"), SUBC("glib"), SUBC("marvelous"), SUBC("debt"), SUBC("bone"), SUBC("school"), SUBC("stage"), SUBC("melted"), SUBC("ubiquitous"), SUBC("poised"), SUBC("island"), SUBC("guiltless"), SUBC("hover"), SUBC("repair"), SUBC("desert"), SUBC("swing"), SUBC("bridge"), SUBC("nest"), SUBC("invite"), SUBC("tree"), SUBC("white"), SUBC("voiceless"), SUBC("wave"), SUBC("eager"), SUBC("pin"), SUBC("makeshift"),
	SUBC("last"), SUBC("stop"), SUBC("picture"), SUBC("ancient"), SUBC("slimy"), SUBC("introduce"), SUBC("produce"), SUBC("frequent"), SUBC("drink"), SUBC("insidious"), SUBC("amusing"), SUBC("permissible"), SUBC("design"), SUBC("itchy"), SUBC("wink"), SUBC("toad"), SUBC("cobweb"), SUBC("delightful"), SUBC("flat"), SUBC("arrest"), SUBC("cold"), SUBC("possessive"), SUBC("milk"), SUBC("sort"), SUBC("standing"), SUBC("list"), SUBC("pedal"), SUBC("kettle"), SUBC("hissing"), SUBC("lumber"),
	SUBC("race"), SUBC("lush"), SUBC("warn"), SUBC("cute"), SUBC("expansion"), SUBC("economic"), SUBC("attract"), SUBC("disastrous"), SUBC("risk"), SUBC("knowledgeable"), SUBC("lighten"), SUBC("condition"), SUBC("pale"), SUBC("short"), SUBC("tricky"), SUBC("interrupt"), SUBC("force"), SUBC("mitten"), SUBC("want"), SUBC("colour"), SUBC("undesirable"), SUBC("join"), SUBC("substantial"), SUBC("cruel"), SUBC("close"), SUBC("achiever"), SUBC("false"), SUBC("clear"), SUBC("gratis"), SUBC("girls"),
	SUBC("question"), SUBC("wealth"), SUBC("sugar"), SUBC("lock"), SUBC("flippant"), SUBC("nippy"), SUBC("preach"), SUBC("magical"), SUBC("refuse"), SUBC("coast"), SUBC("aftermath"), SUBC("afterthought"), SUBC("straw"), SUBC("prick"), SUBC("chivalrous"), SUBC("next"), SUBC("bawdy"), SUBC("reject"), SUBC("yielding"), SUBC("blue"), SUBC("vessel"), SUBC("price"), SUBC("concern"), SUBC("plane"), SUBC("cent"), SUBC("hospitable"), SUBC("lopsided"), SUBC("square"), SUBC("closed"), SUBC("defeated"),
	SUBC("adamant"), SUBC("thaw"), SUBC("pot"), SUBC("plucky"), SUBC("annoyed"), SUBC("unnatural"), SUBC("shiny"), SUBC("meek"), SUBC("polite"), SUBC("texture"), SUBC("line"), SUBC("territory"), SUBC("glass"), SUBC("direction"), SUBC("haunt"), SUBC("smell"), SUBC("fact"), SUBC("fumbling"), SUBC("ragged"), SUBC("dull"), SUBC("steer"), SUBC("division"), SUBC("preserve"), SUBC("breakable"), SUBC("fetch"), SUBC("acceptable"), SUBC("file"), SUBC("happy"), SUBC("listen"), SUBC("tail"),
	SUBC("part"), SUBC("vase"), SUBC("harm"), SUBC("painful"), SUBC("live"), SUBC("stitch"), SUBC("hysterical"), SUBC("strap"), SUBC("clumsy"), SUBC("concerned"), SUBC("basket"), SUBC("art"), SUBC("fall"), SUBC("temporary"), SUBC("welcome"), SUBC("destruction"), SUBC("necessary"), SUBC("steep"), SUBC("drop"), SUBC("phobic"), SUBC("oil"), SUBC("applaud"), SUBC("waiting"), SUBC("chance"), SUBC("toothpaste"), SUBC("support"), SUBC("chubby"), SUBC("scrape"), SUBC("song"), SUBC("rock"),
	SUBC("minister"), SUBC("corn"), SUBC("weak"), SUBC("remain"), SUBC("damaging"), SUBC("demonic"), SUBC("past"), SUBC("mind"), SUBC("stone"), SUBC("minor"), SUBC("drop"), SUBC("sore"), SUBC("mere"), SUBC("mushy"), SUBC("cemetery"), SUBC("icy"), SUBC("pump"), SUBC("amazing"), SUBC("oval"), SUBC("sticks"), SUBC("escape"), SUBC("mighty"), SUBC("skin"), SUBC("friction"), SUBC("cats"), SUBC("terrify"), SUBC("divergent"), SUBC("wistful"), SUBC("camp"), SUBC("yoke"),
	SUBC("offer"), SUBC("rule"), SUBC("end"), SUBC("jellyfish"), SUBC("trick"), SUBC("general"), SUBC("circle"), SUBC("woozy"), SUBC("flash"), SUBC("miniature"), SUBC("judicious"), SUBC("auspicious"), SUBC("superficial"), SUBC("subtract"), SUBC("wrong"), SUBC("land"), SUBC("watch"), SUBC("base"), SUBC("tenuous"), SUBC("tense"), SUBC("office"), SUBC("wing"), SUBC("curved"), SUBC("book"), SUBC("fog"), SUBC("seed"), SUBC("system"), SUBC("unit"), SUBC("gun"), SUBC("hard-to-find"),
	SUBC("start"), SUBC("giraffe"), SUBC("channel"), SUBC("round"), SUBC("announce"), SUBC("twist"), SUBC("appliance"), SUBC("far"), SUBC("well-off"), SUBC("reach"), SUBC("correct"), SUBC("voice"), SUBC("party"), SUBC("lock"), SUBC("ruthless"), SUBC("hypnotic"), SUBC("trains"), SUBC("feeling"), SUBC("purple"), SUBC("space"), SUBC("thankful"), SUBC("religion"), SUBC("credit"), SUBC("potato"), SUBC("number"), SUBC("ambitious"), SUBC("halting"), SUBC("pail"), SUBC("snake"), SUBC("eight"),
	SUBC("gainful"), SUBC("angry"), SUBC("love"), SUBC("blow"), SUBC("unable"), SUBC("young"), SUBC("salt"), SUBC("grandmother"), SUBC("settle"), SUBC("sniff"), SUBC("abiding"), SUBC("incredible"), SUBC("carve"), SUBC("earthy"), SUBC("paper"), SUBC("paint"), SUBC("mate"), SUBC("heartbreaking"), SUBC("basin"), SUBC("analyse"), SUBC("war"), SUBC("stocking"), SUBC("allow"), SUBC("battle"), SUBC("rabid"), SUBC("rejoice"), SUBC("aware"), SUBC("sack"), SUBC("desk"), SUBC("youthful"),
	SUBC("cub"), SUBC("lamp"), SUBC("omniscient"), SUBC("grain"), SUBC("devilish"), SUBC("metal"), SUBC("squealing"), SUBC("attach"), SUBC("real"), SUBC("hill"), SUBC("magic"), SUBC("outstanding"), SUBC("responsible"), SUBC("silent"), SUBC("puncture"), SUBC("fresh"), SUBC("carriage"), SUBC("sail"), SUBC("windy"), SUBC("lavish"), SUBC("productive"), SUBC("pastoral"), SUBC("form"), SUBC("abject"), SUBC("honorable"), SUBC("possess"), SUBC("week"), SUBC("mint"), SUBC("placid"), SUBC("advertisement"),
	SUBC("smelly"), SUBC("clean"), SUBC("frog"), SUBC("dam"), SUBC("glistening"), SUBC("brave"), SUBC("hammer"), SUBC("believe"), SUBC("fuel"), SUBC("ocean"), SUBC("neighborly"), SUBC("awake"), SUBC("long-term"), SUBC("adorable"), SUBC("telling"), SUBC("ceaseless"), SUBC("imagine"), SUBC("answer"), SUBC("ants"), SUBC("helpless"), SUBC("tightfisted"), SUBC("gold"), SUBC("grumpy"), SUBC("handle"), SUBC("mountain"), SUBC("collect"), SUBC("bite-sized"), SUBC("cable"), SUBC("murder"), SUBC("mellow"),
	SUBC("receipt"), SUBC("muddle"), SUBC("meeting"), SUBC("scribble"), SUBC("rough"), SUBC("gleaming"), SUBC("jail"), SUBC("depend"), SUBC("permit"), SUBC("delicate"), SUBC("ethereal"), SUBC("far-flung"), SUBC("look"), SUBC("addicted"), SUBC("teeny"), SUBC("holistic"), SUBC("foolish"), SUBC("act"), SUBC("homeless"), SUBC("plug"), SUBC("various"), SUBC("electric"), SUBC("quilt"), SUBC("airport"), SUBC("apathetic"), SUBC("ink"), SUBC("tangy"), SUBC("bike"), SUBC("queue"), SUBC("door"),
	SUBC("calm"), SUBC("comb"), SUBC("perfect"), SUBC("nonstop"), SUBC("cheese"), SUBC("faded"), SUBC("wish"), SUBC("plant"), SUBC("unadvised"), SUBC("hilarious"), SUBC("rapid"), SUBC("foregoing"), SUBC("alert"), SUBC("kick"), SUBC("safe"), SUBC("letter"), SUBC("empty"), SUBC("fixed"), SUBC("busy"), SUBC("black-and-white"), SUBC("receive"), SUBC("foot"), SUBC("instruct"), SUBC("voyage"), SUBC("cream"), SUBC("pencil"), SUBC("cagey"), SUBC("nonchalant"), SUBC("handy"), SUBC("bells"),
	SUBC("abandoned"), SUBC("educated"), SUBC("fit"), SUBC("elfin"), SUBC("elastic"), SUBC("cook"), SUBC("thumb"), SUBC("three"), SUBC("sophisticated"), SUBC("class"), SUBC("attempt"), SUBC("unsightly"), SUBC("cap"), SUBC("squeeze"), SUBC("proud"), SUBC("tramp"), SUBC("maniacal"), SUBC("dashing"), SUBC("puffy"), SUBC("amused"), SUBC("screw"), SUBC("sweltering"), SUBC("moan"), SUBC("describe"), SUBC("cars"), SUBC("brake"), SUBC("purring"), SUBC("axiomatic"), SUBC("thing"), SUBC("mailbox"),
	SUBC("ruddy"), SUBC("apparel"), SUBC("coach"), SUBC("egg"), SUBC("branch"), SUBC("stick"), SUBC("fry"), SUBC("amusement"), SUBC("need"), SUBC("recondite"), SUBC("things"), SUBC("quirky"), SUBC("pie"), SUBC("perpetual"), SUBC("horrible"), SUBC("jelly"), SUBC("contain"), SUBC("narrow"), SUBC("quiet"), SUBC("satisfy"), SUBC("cellar"), SUBC("boring"), SUBC("education"), SUBC("wrestle"), SUBC("fragile"), SUBC("provide"), SUBC("effect"), SUBC("pies"), SUBC("puny"), SUBC("great"),
	SUBC("frogs"), SUBC("prepare"), SUBC("paddle"), SUBC("rabbit"), SUBC("observation"), SUBC("hands"), SUBC("crib"), SUBC("attack"), SUBC("rose"), SUBC("coherent"), SUBC("back"), SUBC("explode"), SUBC("hulking"), SUBC("cat"), SUBC("subsequent"), SUBC("tray"), SUBC("valuable"), SUBC("natural"), SUBC("cave"), SUBC("repulsive"), SUBC("harsh"), SUBC("overflow"), SUBC("dogs"), SUBC("rod"), SUBC("married"), SUBC("choke"), SUBC("deserve"), SUBC("cabbage"), SUBC("understood"), SUBC("anger"),
	SUBC("shy"), SUBC("wrathful"), SUBC("inquisitive"), SUBC("ring"), SUBC("wheel"), SUBC("face"), SUBC("arrogant"), SUBC("snakes"), SUBC("subdued"), SUBC("labored"), SUBC("float"), SUBC("request"), SUBC("victorious"), SUBC("gusty"), SUBC("yak"), SUBC("pop"), SUBC("dependent"), SUBC("double"), SUBC("rinse"), SUBC("scintillating"), SUBC("eatable"), SUBC("verse"), SUBC("transport"), SUBC("detail"), SUBC("quiet"), SUBC("enter"), SUBC("nerve"), SUBC("towering"), SUBC("needless"), SUBC("bubble"),
	SUBC("doctor"), SUBC("ruin"), SUBC("bead"), SUBC("expand"), SUBC("shop"), SUBC("tent"), SUBC("difficult"), SUBC("celery"), SUBC("judge"), SUBC("statuesque"), SUBC("abaft"), SUBC("wonderful"), SUBC("influence"), SUBC("hole"), SUBC("maid"), SUBC("sea"), SUBC("gentle"), SUBC("witty"), SUBC("even"), SUBC("trashy"), SUBC("turn"), SUBC("hateful"), SUBC("weight"), SUBC("bucket"), SUBC("tasty"), SUBC("unequal"), SUBC("fertile"), SUBC("release"), SUBC("gate"), SUBC("touch"),
	SUBC("fluffy"), SUBC("print"), SUBC("command"), SUBC("horses"), SUBC("compete"), SUBC("sassy"), SUBC("children"), SUBC("girl"), SUBC("smash"), SUBC("workable"), SUBC("key"), SUBC("balance"), SUBC("story"), SUBC("rampant"), SUBC("interfere"), SUBC("distinct"), SUBC("death"), SUBC("dinner"), SUBC("flow"), SUBC("sordid"), SUBC("oatmeal"), SUBC("used"), SUBC("need"), SUBC("limping"), SUBC("tight"), SUBC("tiny"), SUBC("pass"), SUBC("copy"), SUBC("shop"), SUBC("wonder"),
	SUBC("sidewalk"), SUBC("friend"), SUBC("hammer"), SUBC("craven"), SUBC("boil"), SUBC("immense"), SUBC("tense"), SUBC("attractive"), SUBC("squeal"), SUBC("six"), SUBC("vegetable"), SUBC("crook"), SUBC("eminent"), SUBC("injure"), SUBC("mark"), SUBC("obsequious"), SUBC("army"), SUBC("aunt"), SUBC("cake"), SUBC("first"), SUBC("goofy"), SUBC("oceanic"), SUBC("hair"), SUBC("needle"), SUBC("acidic"), SUBC("pan"), SUBC("stretch"), SUBC("digestion"), SUBC("blushing"), SUBC("bat"),
	SUBC("church"), SUBC("sharp"), SUBC("step"), SUBC("chew"), SUBC("riddle"), SUBC("sweet"), SUBC("try"), SUBC("painstaking"), SUBC("bomb"), SUBC("fluttering"), SUBC("squeamish"), SUBC("woman"), SUBC("disagreeable"), SUBC("stroke"), SUBC("legal"), SUBC("conscious"), SUBC("box"), SUBC("produce"), SUBC("synonymous"), SUBC("yam"), SUBC("glorious"), SUBC("red"), SUBC("snails"), SUBC("flower"), SUBC("taste"), SUBC("gaping"), SUBC("quickest"), SUBC("sincere"), SUBC("sulky"), SUBC("alarm"),
	SUBC("employ"), SUBC("collar"), SUBC("talk"), SUBC("box"), SUBC("toes"), SUBC("tomatoes"), SUBC("follow"), SUBC("man"), SUBC("post"), SUBC("jewel"), SUBC("panoramic"), SUBC("heady"), SUBC("way"), SUBC("beef"), SUBC("possible"), SUBC("elbow"), SUBC("man"), SUBC("trouble"), SUBC("humor"), SUBC("tire"), SUBC("strip"), SUBC("voracious"), SUBC("watch"), SUBC("old"), SUBC("blush"), SUBC("flowers"), SUBC("color"), SUBC("broad"), SUBC("remove"), SUBC("defective"),
	SUBC("wealthy"), SUBC("abortive"), SUBC("unusual"), SUBC("partner"), SUBC("faithful"), SUBC("calendar"), SUBC("descriptive"), SUBC("look"), SUBC("pour"), SUBC("knot"), SUBC("invent"), SUBC("afford"), SUBC("history"), SUBC("shade"), SUBC("wait"), SUBC("move"), SUBC("treat"), SUBC("scarecrow"), SUBC("brick"), SUBC("warm"), SUBC("mine"), SUBC("month"), SUBC("wax"), SUBC("license"), SUBC("smell"), SUBC("pack"), SUBC("throat"), SUBC("snow"), SUBC("science"), SUBC("aback"),
	SUBC("punch"), SUBC("silk"), SUBC("nappy"), SUBC("hallowed"), SUBC("trap"), SUBC("belong"), SUBC("form"), SUBC("error"), SUBC("rainy"), SUBC("innate"), SUBC("canvas"), SUBC("scene"), SUBC("avoid"), SUBC("accept"), SUBC("tie"), SUBC("upbeat"), SUBC("cakes"), SUBC("wrist"), SUBC("weary"), SUBC("wound"), SUBC("jagged"), SUBC("paltry"), SUBC("vagabond"), SUBC("miscreant"), SUBC("fade"), SUBC("money"), SUBC("turn"), SUBC("industry"), SUBC("hang"), SUBC("include"),
	SUBC("toe"), SUBC("smoke"), SUBC("silent"), SUBC("bolt"), SUBC("groan"), SUBC("launch"), SUBC("trucks"), SUBC("saw"), SUBC("ray"), SUBC("kind"), SUBC("probable"), SUBC("tug"), SUBC("sip"), SUBC("clean"), SUBC("jealous"), SUBC("abhorrent"), SUBC("shave"), SUBC("jail"), SUBC("wicked"), SUBC("exultant"), SUBC("cautious"), SUBC("behave"), SUBC("organic"), SUBC("normal"), SUBC("letters"), SUBC("tooth"), SUBC("soup"), SUBC("deer"), SUBC("greedy"), SUBC("animated"),
	SUBC("royal"), SUBC("meaty"), SUBC("insect"), SUBC("unite"), SUBC("utopian"), SUBC("cherries"), SUBC("grandfather"), SUBC("roll"), SUBC("marble"), SUBC("courageous"), SUBC("orange"), SUBC("teeth"), SUBC("tawdry"), SUBC("erect"), SUBC("respect"), SUBC("periodic"), SUBC("love"), SUBC("interest"), SUBC("twist"), SUBC("fire"), SUBC("lie"), SUBC("reason"), SUBC("badge"), SUBC("guarantee"), SUBC("scarf"), SUBC("clever"), SUBC("confess"), SUBC("crooked"), SUBC("ball"), SUBC("bright"),
	SUBC("raise"), SUBC("famous"), SUBC("volleyball"), SUBC("reaction"), SUBC("flame"), SUBC("star"), SUBC("mixed"), SUBC("move"), SUBC("change"), SUBC("travel"), SUBC("prose"), SUBC("consist"), SUBC("coil"), SUBC("support"), SUBC("rob"), SUBC("zephyr"), SUBC("bed"), SUBC("scale"), SUBC("receptive"), SUBC("encourage"), SUBC("continue"), SUBC("perform"), SUBC("serve"), SUBC("sound"), SUBC("crabby"), SUBC("strengthen"), SUBC("typical"), SUBC("measure"), SUBC("donkey"), SUBC("push"),
	SUBC("zip"), SUBC("high"), SUBC("blade"), SUBC("melt"), SUBC("fail"), SUBC("frantic"), SUBC("tub"), SUBC("pat"), SUBC("cross"), SUBC("sneeze"), SUBC("dynamic"), SUBC("distribution"), SUBC("tongue"), SUBC("jump"), SUBC("steadfast"), SUBC("number"), SUBC("modern"), SUBC("clap"), SUBC("inconclusive"), SUBC("dead"), SUBC("tested"), SUBC("rural"), SUBC("authority"), SUBC("borrow"), SUBC("search"), SUBC("rotten"), SUBC("awesome"), SUBC("last"), SUBC("heap"), SUBC("drain"),
	SUBC("pick"), SUBC("action"), SUBC("resolute"), SUBC("unfasten"), SUBC("railway"), SUBC("odd"), SUBC("macabre"), SUBC("suggestion"), SUBC("plough"), SUBC("stale"), SUBC("unkempt"), SUBC("impolite"), SUBC("impossible"), SUBC("shaky"), SUBC("nauseating"), SUBC("knotty"), SUBC("cute"), SUBC("swim"), SUBC("add"), SUBC("whole"), SUBC("laugh"), SUBC("messy"), SUBC("worm"), SUBC("plantation"), SUBC("succinct"), SUBC("change"), SUBC("quarrelsome"), SUBC("earthquake"), SUBC("wool"), SUBC("mix"),
	SUBC("little"), SUBC("detailed"), SUBC("spectacular"), SUBC("vigorous"), SUBC("symptomatic"), SUBC("engine"), SUBC("shaggy"), SUBC("cut"), SUBC("cattle"), SUBC("defiant"), SUBC("signal"), SUBC("development"), SUBC("kitty"), SUBC("scatter"), SUBC("physical"), SUBC("limit"), SUBC("mist"), SUBC("rub"), SUBC("writer"), SUBC("unarmed"), SUBC("consider"), SUBC("dazzling"), SUBC("hot"), SUBC("obscene"), SUBC("obeisant"), SUBC("hurried"), SUBC("hook"), SUBC("rabbits"), SUBC("crawl"), SUBC("profuse"),
	SUBC("tidy"), SUBC("loss"), SUBC("straight"), SUBC("bad"), SUBC("nutritious"), SUBC("protect"), SUBC("theory"), SUBC("page"), SUBC("gray"), SUBC("medical"), SUBC("skillful"), SUBC("dislike"), SUBC("imaginary"), SUBC("request"), SUBC("attend"), SUBC("winter"), SUBC("grip"), SUBC("bless"), SUBC("spooky"), SUBC("test"), SUBC("snore"), SUBC("afraid"), SUBC("mean"), SUBC("bare"), SUBC("spark"), SUBC("toothbrush"), SUBC("long"), SUBC("befitting"), SUBC("motion"), SUBC("bruise"),
	SUBC("tart"), SUBC("pipe"), SUBC("ignorant"), SUBC("transport"), SUBC("trade"), SUBC("nod"), SUBC("march"), SUBC("squash"), SUBC("rain"), SUBC("north"), SUBC("rhetorical"), SUBC("damp"), SUBC("deadpan"), SUBC("freezing"), SUBC("thundering"), SUBC("romantic"), SUBC("undress"), SUBC("lovely"), SUBC("materialistic"), SUBC("flimsy"), SUBC("discover"), SUBC("chemical"), SUBC("meddle"), SUBC("abstracted"), SUBC("pickle"), SUBC("intend"), SUBC("scrawny"), SUBC("thread"), SUBC("temper"), SUBC("equal"),
	SUBC("alleged"), SUBC("shirt"), SUBC("festive"), SUBC("profit"), SUBC("dramatic"), SUBC("roomy"), SUBC("evasive"), SUBC("scent"), SUBC("battle"), SUBC("fax"), SUBC("rainstorm"), SUBC("uncovered"), SUBC("melodic"), SUBC("stretch"), SUBC("learned"), SUBC("petite"), SUBC("idiotic"), SUBC("breezy"), SUBC("finger"), SUBC("ban"), SUBC("mass"), SUBC("clip"), SUBC("stem"), SUBC("cracker"), SUBC("separate"), SUBC("macho"), SUBC("connect"), SUBC("observe"), SUBC("heavy"), SUBC("guess"),
	SUBC("ugliest"), SUBC("stay"), SUBC("pet"), SUBC("tick"), SUBC("abusive"), SUBC("bustling"), SUBC("actor"), SUBC("easy"), SUBC("spiky"), SUBC("pump"), SUBC("surround"), SUBC("show"), SUBC("business"), SUBC("scandalous"), SUBC("volcano"), SUBC("spare"), SUBC("lamentable"), SUBC("second-hand"), SUBC("rich"), SUBC("degree"), SUBC("market"), SUBC("wriggle"), SUBC("queen"), SUBC("machine"), SUBC("small"), SUBC("seashore"), SUBC("fire"), SUBC("spring"), SUBC("chickens"), SUBC("back"),
	SUBC("rock"), SUBC("deeply"), SUBC("lunch"), SUBC("flight"), SUBC("heal"), SUBC("accessible"), SUBC("charming"), SUBC("glamorous"), SUBC("statement"), SUBC("tin"), SUBC("erratic"), SUBC("cycle"), SUBC("brawny"), SUBC("disillusioned"), SUBC("capable"), SUBC("shivering"), SUBC("vague"), SUBC("glow"), SUBC("educate"), SUBC("leg"), SUBC("momentous"), SUBC("sock"), SUBC("absent"), SUBC("complex"), SUBC("wacky"), SUBC("massive"), SUBC("sudden"), SUBC("doll"), SUBC("soothe"), SUBC("secret"),
	SUBC("whisper"), SUBC("loud"), SUBC("tasteful"), SUBC("faulty"), SUBC("weigh"), SUBC("annoying"), SUBC("wretched"), SUBC("spot"), SUBC("marry"), SUBC("yard"), SUBC("whimsical"), SUBC("tour"), SUBC("raspy"), SUBC("spot"), SUBC("rail"), SUBC("anxious"), SUBC("insurance"), SUBC("itch"), SUBC("delight"), SUBC("lowly"), SUBC("claim"), SUBC("bee"), SUBC("arrive"), SUBC("aspiring"), SUBC("purpose"), SUBC("direful"), SUBC("ludicrous"), SUBC("tacit"), SUBC("rate"), SUBC("agreeable"),
	SUBC("knot"), SUBC("sleep"), SUBC("fireman"), SUBC("internal"), SUBC("wide-eyed"), SUBC("glove"), SUBC("dad"), SUBC("blind"), SUBC("fallacious"), SUBC("tedious"), SUBC("familiar"), SUBC("save"), SUBC("pleasure"), SUBC("beautiful"), SUBC("square"), SUBC("taste"), SUBC("empty"), SUBC("debonair"), SUBC("bikes"), SUBC("legs"), SUBC("balance"), SUBC("irritate"), SUBC("apologise"), SUBC("lackadaisical"), SUBC("eggs"), SUBC("fix"), SUBC("dispensable"), SUBC("hunt"), SUBC("quartz"), SUBC("group"),
	SUBC("literate"), SUBC("vengeful"), SUBC("earth"), SUBC("control"), SUBC("cover"), SUBC("drunk"), SUBC("reminiscent"), SUBC("ticket"), SUBC("cheer"), SUBC("government"), SUBC("stop"), SUBC("public"), SUBC("boast"), SUBC("hanging"), SUBC("label"), SUBC("brief"), SUBC("order"), SUBC("encouraging"), SUBC("enthusiastic"), SUBC("table"), SUBC("reduce"), SUBC("side"), SUBC("hesitant"), SUBC("wave"), SUBC("cactus"), SUBC("spade"), SUBC("mysterious"), SUBC("guttural"), SUBC("calculator"), SUBC("rice"),
	SUBC("dusty"), SUBC("overwrought"), SUBC("nation"), SUBC("blink"), SUBC("alcoholic"), SUBC("care"), SUBC("bat"), SUBC("cheerful"), SUBC("sticky"), SUBC("exotic"), SUBC("slippery"), SUBC("spell"), SUBC("promise"), SUBC("ashamed"), SUBC("ignore"), SUBC("colossal"), SUBC("moldy"), SUBC("stomach"), SUBC("hop"), SUBC("overt"), SUBC("umbrella"), SUBC("scream"), SUBC("callous"), SUBC("tiresome"), SUBC("discovery"), SUBC("poison"), SUBC("mountainous"), SUBC("scattered"), SUBC("flower"), SUBC("quarter"),
	SUBC("well-groomed"), SUBC("carpenter"), SUBC("invention"), SUBC("border"), SUBC("roll"), SUBC("crayon"), SUBC("racial"), SUBC("groovy"), SUBC("spray"), SUBC("bashful"), SUBC("nifty"), SUBC("replace"), SUBC("leather"), SUBC("sofa"), SUBC("expensive"), SUBC("aloof"), SUBC("tame"), SUBC("beginner"), SUBC("count"), SUBC("crow"), SUBC("repeat"), SUBC("field"), SUBC("found"), SUBC("present"), SUBC("tap"), SUBC("screw"), SUBC("soak"), SUBC("accidental"), SUBC("wide"), SUBC("chunky"),
	SUBC("illustrious"), SUBC("simple"), SUBC("robust"), SUBC("writing"), SUBC("land"), SUBC("approval"), SUBC("mother"), SUBC("jazzy"), SUBC("vast"), SUBC("inexpensive"), SUBC("harmonious"), SUBC("swift"), SUBC("silver"), SUBC("savory"), SUBC("afternoon"), SUBC("spoil"), SUBC("cloth"), SUBC("agreement"), SUBC("drum"), SUBC("unwieldy"), SUBC("amuck"), SUBC("language"), SUBC("mindless"), SUBC("plant"), SUBC("godly"), SUBC("alert"), SUBC("fantastic"), SUBC("disapprove"), SUBC("punish"), SUBC("four"),
	SUBC("belief"), SUBC("turkey"), SUBC("enchanting"), SUBC("fool"), SUBC("fearful"), SUBC("absorbing"), SUBC("hapless"), SUBC("tiger"), SUBC("remarkable"), SUBC("nutty"), SUBC("orange"), SUBC("aromatic"), SUBC("wilderness"), SUBC("cast"), SUBC("bore"), SUBC("deliver"), SUBC("lethal"), SUBC("word"), SUBC("porter"), SUBC("thunder"), SUBC("ill"), SUBC("unknown"), SUBC("dog"), SUBC("buzz"), SUBC("chop"), SUBC("damaged"), SUBC("hot"), SUBC("laugh"), SUBC("ladybug"), SUBC("multiply"),
	SUBC("grape"), SUBC("explain"), SUBC("jam"), SUBC("roof"), SUBC("example"), SUBC("seemly"), SUBC("smoke"), SUBC("worried"), SUBC("sponge"), SUBC("crush"), SUBC("obedient"), SUBC("strong"), SUBC("seat"), SUBC("work"), SUBC("cowardly"), SUBC("account"), SUBC("tow"), SUBC("extra-small"), SUBC("drag"), SUBC("pine"), SUBC("wander"), SUBC("cumbersome"), SUBC("picayune"), SUBC("salty"), SUBC("desire"), SUBC("ill-fated"), SUBC("scorch"), SUBC("treatment"), SUBC("skip"), SUBC("unused"),
	SUBC("growth"), SUBC("wasteful"), SUBC("deafening"), SUBC("uptight"), SUBC("premium"), SUBC("card"), SUBC("observant"), SUBC("obnoxious"), SUBC("pigs"), SUBC("talk"), SUBC("astonishing"), SUBC("lettuce"), SUBC("start"), SUBC("trip"), SUBC("activity"), SUBC("attraction"), SUBC("jumbled"), SUBC("wall"), SUBC("knowing"), SUBC("ordinary"), SUBC("domineering"), SUBC("garrulous"), SUBC("frightening"), SUBC("lively"), SUBC("unlock"), SUBC("match"), SUBC("shape"), SUBC("splendid"), SUBC("wrap"), SUBC("wholesale"),
	SUBC("ask"), SUBC("concentrate"), SUBC("thin"), SUBC("psychotic"), SUBC("wiry"), SUBC("measly"), SUBC("thirsty"), SUBC("dry"), SUBC("truculent"), SUBC("like"), SUBC("scary"), SUBC("monkey"), SUBC("spiteful"), SUBC("summer"), SUBC("obsolete"), SUBC("pretend"), SUBC("room"), SUBC("run"), SUBC("lyrical"), SUBC("position"), SUBC("grieving"), SUBC("husky"), SUBC("harmony"), SUBC("sheet"), SUBC("rain"), SUBC("jolly"), SUBC("offer"), SUBC("snow"), SUBC("excuse"), SUBC("lacking"),
	SUBC("gabby"), SUBC("successful"), SUBC("healthy"), SUBC("regret"), SUBC("tremble"), SUBC("lace"), SUBC("stupid"), SUBC("flaky"), SUBC("wanting"), SUBC("experience"), SUBC("loose"), SUBC("wry"), SUBC("colorful"), SUBC("hideous"), SUBC("liquid"), SUBC("absurd"), SUBC("zoom"), SUBC("two"), SUBC("steam"), SUBC("warlike"), SUBC("grab"), SUBC("heat"), SUBC("basketball"), SUBC("swanky"), SUBC("birds"), SUBC("five"), SUBC("breath"), SUBC("calculating"), SUBC("approve"), SUBC("dangerous"),
	SUBC("club"), SUBC("giants"), SUBC("uncle"), SUBC("downtown"), SUBC("extend"), SUBC("dusty"), SUBC("jobless"), SUBC("impress"), SUBC("press"), SUBC("grandiose"), SUBC("jam"), SUBC("useless"), SUBC("female"), SUBC("board"), SUBC("doubt"), SUBC("report"), SUBC("sound"), SUBC("mourn"), SUBC("flagrant"), SUBC("sigh"), SUBC("boot"), SUBC("suspend"), SUBC("entertaining"), SUBC("precious"), SUBC("efficacious"), SUBC("tame"), SUBC("old-fashioned"), SUBC("spicy"), SUBC("quicksand"), SUBC("vulgar"),
	SUBC("house"), SUBC("jaded"), SUBC("fine"), SUBC("roasted"), SUBC("selection"), SUBC("near"), SUBC("curious"), SUBC("caring"), SUBC("detect"), SUBC("zoo")
};

int const		g_test_keys_count = sizeof(g_test_keys) / sizeof(t_sub);

static int		test_h(t_sub s)
{
	int				h;
	int				i;

	i = -1;
	h = 0;
	while (++i < s.length)
		h = (h << 2) + s.str[i];
	return (h);
}

static t_ulong	test_add(t_hmap *map, int count)
{
	int				i;
	t_ulong			t;

	t = ft_clock(0);
	for (i = 0; i < count; ++i)
	{
		ft_hmapputp(map, g_test_keys[rand() % g_test_keys_count],
			(void*)(g_test_keys + (rand() % g_test_keys_count)));
	}
	t = ft_clock(t);
	ft_printf("Added %d: size:%d; time:%lld\n", count, map->size, t);
	return (t);
}

static void		print_hmap_debug(t_hmap *map)
{
	int				i;
	int				len;
	int				total_len;
	t_h				*tmp;

	PS("hmap:");
	total_len = 0;
	i = -1;
	while (++i < map->alloc_size)
	{
		len = 0;
		tmp = map->data[i];
		while (tmp != NULL)
		{
			len++;
			tmp = tmp->next;
		}
		total_len += len;
		P(" %d", len);
	}
	NL;
	if (total_len != map->size)
		P("Error: total_len != size (%d, %d)", total_len, map->size), NL;
}

static t_ulong	test_get(t_hmap *map, int count)
{
	int				i;
	int				found;
	t_ulong			t;

	found = 0;
	t = ft_clock(0);
	for (i = 0; i < count; ++i)
	{
		if (ft_hmapget(map, g_test_keys[rand() % g_test_keys_count]) != NULL)
			found++;
	}
	t = ft_clock(t);
	ft_printf("Get %d: found:%d; time:%lld\n", count, found, t);
	return (t);
}

int				main(int argc, char **argv)
{
	t_hmap			*map;
	t_ulong			t;
	int				alloc_size;

	alloc_size = (argc > 1) ? ft_atoi(argv[1]) : 50;
	srand(ft_clock(0));
	map = ft_hmapnew(alloc_size, &test_h);
	ft_printf("Start test: alloc_size:%d\n", map->alloc_size);
	print_hmap_debug(map);
	t = test_add(map, 20);
	print_hmap_debug(map);
	t += test_add(map, 200);
	print_hmap_debug(map);
	t += test_add(map, 1000);
	t += test_add(map, 20);
	t += test_add(map, 200);
	t += test_add(map, 2000);
	print_hmap_debug(map);
	ft_printf("Total time: %lld\n", t);
	t = test_get(map, 5);
	t += test_get(map, 20);
	t += test_get(map, 200);
	t += test_get(map, g_test_keys_count);
	ft_printf("Total time: %lld\n", t);
	print_hmap_debug(map);
	return (0);
}
